module cout_b_gen(

	input clk,
	input reset,
	input [31:0] freq_b,
	input [31:0] freq_base, //регистр, содержащий значение опорной частоты. Если не требуется задавать извне, можно раскомментировать строку "parameter freq_base = ..."
	input [31:0] time_del,//регистр, содержащий значение делителя, на который сдвигается значение опорной частоты для уменьшения интервала измерения
	output reg cout_b
	);
typedef enum logic [1:0] {S0, S1, S2, S3} statetype;
statetype state, nextstate;

always_ff @(posedge clk, posedge reset)
	if (reset)	state <= S0;
	else			state <= nextstate;

//next state logic
always_comb
	case (state)
		S0:		if (freq_b == ((freq_base >> time_del) - 1))	nextstate = S1;
					else 														nextstate = S0;
		S1:		nextstate = S2;
		S2:		nextstate = S3;
		S3:		nextstate = S0;
		default:	nextstate = S0;
	endcase

//output logic
assign cout_b = state[0];

endmodule	