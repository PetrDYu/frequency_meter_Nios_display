module freq_m_module
(
	input clk_base, // опорная частота, по которой остчитывается промежуток времени (здесь 1с)
	input clk_in, // измеряемая частота
	output reg [31:0] freq_mem, // регистр, сохраняющий измеренное значение частоты сигнала, подаваемого на вход freq_in
	output cout_i, // сигнал переполнения счётчика измеряемой частоты
	output reg cout_b // сигнал переполнения счётчика опорной частоты
);

/*модуль freq_m - частотомер, измеряет частоту, поступающую на линию clk_in.
Измеренное значение раз в секунду возвращается через регистр freq_mem.
Сигнал смены значения соответствует сигналу cout_b.
Сигнал cout_i служит для отслеживания переполнения счётчика измеряемой частоты.

Исходя из размерности счётчика (32 бита), максимальная измеряемая частота (2^32 - 1) Гц = 4_294_967_295 Гц
Если предполагается измерение больших частот, необходимо использовать сигнал cout_i
для отслеживания перехода счётчика через 0.

Размерность счётчика опорной частоты такая же, следовательно, максимальное значение
опорной частоты такое же.

*/


wire [31:0] freq_b, freq_i; // шины для передачи результатов работы счётчиков

reg sclr_b = 0, aclr_i = 0;
/* cout_b - формируемый вне счётчика сигнал переполнения счётчика опорной частоты (зависит от параметра freq_base)
	sclr_b - сигнал синхронного сброса счётчика опорной частоты
	aclr_i - сигнал асинхронного сброса счётчика измеряемой частоты*/

parameter freq_base = 31'd200_000_000; // параметр, определяющий значение опорной частоты (необходимо задать перед использованием)

initial
begin
	
	cout_b = 0;//инициализация cout_b
	
end

// блок для формирования сигналов cout_b, sclr_b, aclr_i
always @(posedge clk_base)
begin
	
	/*сигнал cout_b становится в 1, если счётчик опорной частоты досчитывает до значения (freq_base - 1)*/
	if (freq_b == freq_base - 1) cout_b = 1;
	else cout_b = 0;
	
	/* при достижении счётчиком опорной частоты значения freq_base счётчики
	опорной и измеряемой частоты сбрасываются в 0 при помощи сигналов sclr_b и aclr_i*/
	if (freq_b == freq_base)
	begin
	
		sclr_b = 1;
		aclr_i = 1;
		
	end
	// после сброса счётчиков сигналы sclr_b и aclr_i устанавливаются обратно в 0	
	if (freq_b == 1'b0)
	begin
	
		sclr_b = 0;
		aclr_i = 0;
		
	end
	
end


//Счётчик опорной частоты

Counter b_c
(
	
	.aclr(1'b0),
	.clock(clk_base),
	.sclr(sclr_b),
	.q(freq_b)
	
);

//Счётчик измеряемой частоты

Counter i_c
(
	
	.aclr(aclr_i),
	.clock(clk_in),
	.sclr(1'b0),
	.cout(cout_i),
	.q(freq_i)
	
);


/* при установке сигнала cout_b в 1 значение измеряемой частоты 
сохраняется в выходном регистре freq_mem*/
always @(posedge cout_b)
begin
	
	freq_mem = freq_i;
	
end

endmodule 