// Project:	DLX 
// Entity	Global Functions
// File		globals_fns.h
// Date:	26 Sept 2000

// basic bitwise aritmetic functions
// (this is required as global_fns.java has same methods)
// These methods are simplistic
int BitOp(double a, double b, char op);
int BitComplement(double a);
int BitShiftRight(double a, int shift);
int BitShiftLeft(double a, int shift);

//Additional methods which type convert inputs and send to above methods
int BitOp(int a, double b, char op);
int BitOp(double a, int b, char op);
int BitOp(int a, int b, char op);
int BitShiftRight(int a, int shift);
int BitShiftLeft(int a, int shift);

int pow(int, int);  // forms exponential without using doubles

float floatFromInt(int v);
int floatToInt(float d);
// uint IntToUint(int d);
// >>>S1
int doubleToInt(double d);

class t_reg_args Decode_Register(char *Instruction);

int Decode_LOAD(t_mips_instrn_set Instruction);

int Decode_STORE(t_mips_instrn_set Instruction);

int Decode_MOVE(t_mips_instrn_set Instruction);

int Decode_HILO(t_mips_instrn_set Instruction);

int Decode_ALU(t_mips_instrn_set Instruction);

int Decode_ALUI(t_mips_instrn_set Instruction);

int Decode_JIMM(t_mips_instrn_set Instruction);

int Decode_JREG(t_mips_instrn_set Instruction);

int Decode_BRNC(t_mips_instrn_set Instruction);

int Decode_BRNCI(t_mips_instrn_set Instruction);

//int Decode_FLPT(t_mips_instrn_set Instruction);

//int Decode_COMP(t_mips_instrn_set Instruction);

//int Decode_DBL(t_mips_instrn_set Instruction);

int is_a_function(t_mips_instrn_set Instruction);





