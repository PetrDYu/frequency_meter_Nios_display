module cout_b_gen #(parameter N = 1)(

	input clk,
	input reset,
	input [31:0] freq_b,
	input [31:0] freq_base, //регистр, содержащий значение опорной частоты. Если не требуется задавать извне, можно раскомментировать строку "parameter freq_base = ..."
	input [31:0] time_del,//регистр, содержащий значение делителя, на который сдвигается значение опорной частоты для уменьшения интервала измерения
	output reg cout_b
	);

generate

	if(N == 1)			begin	typedef enum logic [1:0] {S0, S1} statetype;	end
	else if (N == 2)	begin	typedef enum logic [1:0] {S0, S1, S2, S3} statetype;	end
	else					begin	typedef enum logic [1:0] {S0, S1, S2, S3, S4, S5} statetype;	end

endgenerate

statetype state, nextstate;

always_ff @(posedge clk, posedge reset)
	if (reset)	state <= S0;
	else			state <= nextstate;

//next state logic
generate
	
	if(N == 1)
	begin
		always_comb
			case (state)
				S0:		if (freq_b == ((freq_base >> time_del) - 1))	nextstate = S1;
							else 														nextstate = S0;
				S1:		nextstate = S0;
				default:	nextstate = S0;
			endcase
	end
	else if (N == 2)
	begin
		always_comb
			case (state)
				S0:		if (freq_b == ((freq_base >> time_del) - 1))	nextstate = S1;
							else 														nextstate = S0;
				S1:		nextstate = S2;
				S2:		nextstate = S3;
				S3:		nextstate = S0;
				default:	nextstate = S0;
			endcase
	end
	else
	begin
		always_comb
			case (state)
				S0:		if (freq_b == ((freq_base >> time_del) - 1))	nextstate = S1;
							else 														nextstate = S0;
				S1:		nextstate = S2;
				S2:		nextstate = S3;
				S3:		nextstate = S4;
				S4:		nextstate = S5;
				S5:		nextstate = S0;
				default:	nextstate = S0;
			endcase
	end

endgenerate

//output logic
assign cout_b = state[0];

endmodule	