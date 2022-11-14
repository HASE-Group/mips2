int pow(int base, int exp)
{
	int res=1;
	for (int i=0; i<exp; i++) 
		res *= base;
	return res;
}

float floatFromInt(int v) {
	float res;
	int *p = (int*)(&res);
	*p = v;
	//printf("float<-Int: %d %f.\n", v, res);
	return res;
}

int floatToInt(float d) {
	int *p = (int*)(&d);
	//printf("float->int: %f %d.\n", d, *p);
	return *p;
}


t_reg_args Decode_Register(char *Input_Reg)
{
	t_reg_args new_reg;

	if (Input_Reg[0]=='R')
	{
		new_reg.type='R';
		new_reg.number=atoi(Input_Reg+1);
		new_reg.index=0;
	} 
	else if (Input_Reg[0]=='F')
	{
		new_reg.type='F';
		new_reg.number=atoi(Input_Reg+1);
		new_reg.index=0;
	}
	else if (Input_Reg[0]=='S')
	{
		new_reg.type='S';
		new_reg.number=atoi(Input_Reg+1);
		new_reg.index=0;
	}
	else
	{
		char temp_str[100];
		strcpy(temp_str,Input_Reg);
		char *str1=strstr(Input_Reg,"(");
		str1[0]='\0';
		new_reg.index=atoi(temp_str);
		char *str2=str1+1;
		if (str2[0]=='R')
		{new_reg.type='R';}
		else if (str2[0]=='S')
		{new_reg.type='S';}
		else
		{new_reg.type='F';}
		str2++;
		str2[strlen(str2)-1]='\0';
		new_reg.number=atoi(str2);
	}
	return new_reg;
}
/*
int Decode_DBL(t_mips_instrn_set Instruction)
{
	if(
			Instruction.function == t_mips_instrn_set::JAL
			||Instruction.function == t_mips_instrn_set::JALR
	 )
		return 1;
	return 0;
}

*/
int is_a_function(t_mips_instrn_set Instruction)
{
	if (Instruction.function == t_mips_instrn_set::VOID
			|| Instruction.function == t_mips_instrn_set::LB
			|| Instruction.function == t_mips_instrn_set::LBU
			|| Instruction.function == t_mips_instrn_set::SB
			|| Instruction.function == t_mips_instrn_set::LH
			|| Instruction.function == t_mips_instrn_set::LHU
			|| Instruction.function == t_mips_instrn_set::SH
			|| Instruction.function == t_mips_instrn_set::LW
			|| Instruction.function == t_mips_instrn_set::SW
			|| Instruction.function == t_mips_instrn_set::LWC1
			|| Instruction.function == t_mips_instrn_set::SWC1
			|| Instruction.function == t_mips_instrn_set::ADDI
			|| Instruction.function == t_mips_instrn_set::ADDIU
			|| Instruction.function == t_mips_instrn_set::SLTI
			|| Instruction.function == t_mips_instrn_set::SLTIU
			|| Instruction.function == t_mips_instrn_set::ANDI
			|| Instruction.function == t_mips_instrn_set::ORI
			|| Instruction.function == t_mips_instrn_set::XORI
			|| Instruction.function == t_mips_instrn_set::LUI
			|| Instruction.function == t_mips_instrn_set::ADD
			|| Instruction.function == t_mips_instrn_set::ADDU
			|| Instruction.function == t_mips_instrn_set::SUB
			|| Instruction.function == t_mips_instrn_set::SUBU
			|| Instruction.function == t_mips_instrn_set::SLT
			|| Instruction.function == t_mips_instrn_set::SLTU
			|| Instruction.function == t_mips_instrn_set::AND
			|| Instruction.function == t_mips_instrn_set::OR
			|| Instruction.function == t_mips_instrn_set::XOR
			|| Instruction.function == t_mips_instrn_set::NOR
			|| Instruction.function == t_mips_instrn_set::SLL
			|| Instruction.function == t_mips_instrn_set::SRL
			|| Instruction.function == t_mips_instrn_set::SRA
			|| Instruction.function == t_mips_instrn_set::SLLV
			|| Instruction.function == t_mips_instrn_set::SRLV
			|| Instruction.function == t_mips_instrn_set::SRAV
			|| Instruction.function == t_mips_instrn_set::MULT
			|| Instruction.function == t_mips_instrn_set::MULTU
			|| Instruction.function == t_mips_instrn_set::DIV
			|| Instruction.function == t_mips_instrn_set::DIVU
			|| Instruction.function == t_mips_instrn_set::MFHI
			|| Instruction.function == t_mips_instrn_set::MTHI
			|| Instruction.function == t_mips_instrn_set::MFLO
			|| Instruction.function == t_mips_instrn_set::MTLO
			|| Instruction.function == t_mips_instrn_set::J
//			|| Instruction.function == t_mips_instrn_set::JAL
			|| Instruction.function == t_mips_instrn_set::JR
//			|| Instruction.function == t_mips_instrn_set::JALR
			|| Instruction.function == t_mips_instrn_set::BEQ
			|| Instruction.function == t_mips_instrn_set::BNE
			|| Instruction.function == t_mips_instrn_set::BLEZ
			|| Instruction.function == t_mips_instrn_set::BGTZ
			|| Instruction.function == t_mips_instrn_set::BLTZ
			|| Instruction.function == t_mips_instrn_set::BGEZ
//			|| Instruction.function == t_mips_instrn_set::BLTZAL
//			|| Instruction.function == t_mips_instrn_set::BGEZAL
			|| Instruction.function == t_mips_instrn_set::BREAK
			|| Instruction.function == t_mips_instrn_set::NOP
			|| Instruction.function == t_mips_instrn_set::ABSS
			|| Instruction.function == t_mips_instrn_set::ADDS
			|| Instruction.function == t_mips_instrn_set::BC1F
			|| Instruction.function == t_mips_instrn_set::BC1T
			|| Instruction.function == t_mips_instrn_set::CFS
			|| Instruction.function == t_mips_instrn_set::CEQS
			|| Instruction.function == t_mips_instrn_set::COLTS
			|| Instruction.function == t_mips_instrn_set::COLES
			|| Instruction.function == t_mips_instrn_set::CFC1
			|| Instruction.function == t_mips_instrn_set::CTC1
			|| Instruction.function == t_mips_instrn_set::CVTSW
			|| Instruction.function == t_mips_instrn_set::CVTWS
			|| Instruction.function == t_mips_instrn_set::DIVS
			|| Instruction.function == t_mips_instrn_set::MFC1
			|| Instruction.function == t_mips_instrn_set::MOVS
			|| Instruction.function == t_mips_instrn_set::MTC1
			|| Instruction.function == t_mips_instrn_set::MULS
			|| Instruction.function == t_mips_instrn_set::NEGS
			|| Instruction.function == t_mips_instrn_set::SUBS
			)
			return 1;
	return 0;
}
