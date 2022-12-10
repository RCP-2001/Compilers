* ** ** ** ** ** ** ** ** ** ** ** **
*FUNCTION input
1 : ST 3, -1(1)Store return address
2 : IN 2, 2, 2 Grab int input 
3 : LD 3, -1(1)Load return address
4 : LD 1, 0(1)Adjust fp
5 : JMP 7, 0(3)Return
*END FUNCTION input
************************** 
*FUNCTION output 
6 : ST 3, -1(1)Store return address
7 : LD 3, -2(1)Load parameter 
8 : OUT 3, 3, 3 Output integer 
9 : LD 3, -1(1)Load return address
10 : LD 1, 0(1)Adjust fp
11 : JMP 7, 0(3)Return
*END FUNCTION output 
* 
************************* 
*FUNCTION inputb 
12 : ST 3, -1(1)Store return address
13 : INB 2, 2, 2 Grab bool input
14 : LD 3, -1(1)Load return address
15 : LD 1, 0(1)Adjust fp
16 : JMP 7, 0(3)Return
*END FUNCTION inputb 
* 
*************************
*FUNCTION outputb 
17 : ST 3, -1(1)Store return address
18 : LD 3, -2(1)Load parameter 
19 : OUTB 3, 3, 3 Output bool 
20 : LD 3, -1(1)Load return address
21 : LD 1, 0(1)Adjust fp
22 : JMP 7, 0(3)Return 
*END FUNCTION outputb
* 
*************************
*FUNCTION inputc 
23 : ST 3, -1(1)Store return address
24 : INC 2, 2, 2 Grab char input 
25 : LD 3, -1(1)Load return address
26 : LD 1, 0(1)Adjust fp
27 : JMP 7, 0(3)Return
*END FUNCTION inputc
* 
*************************
*FUNCTION outputc 
28 : ST 3, -1(1)Store return address
29 : LD 3, -2(1)Load parameter 
30 : OUTC 3, 3, 3 Output char 
31 : LD 3, -1(1)Load return address
32 : LD 1, 0(1)Adjust fp
33 : JMP 7, 0(3)Return
*END FUNCTION outputc
* 
*************************
*FUNCTION outnl 
34 : ST 3, -1(1)Store return address
35 : OUTNL 3, 3, 3 Output a newline
36 : LD 3, -1(1)Load return address
37 : LD 1, 0(1)Adjust fp
38 : JMP 7, 0(3)Return
*END FUNCTION outnl 
* 
*************************
* ** ** ** ** ** ** ** ** ** ** ** ** 
* FUNC main
* TOFF = -2
39 : ST  3,-1(1) Store Ret Addr
* COMPOUND
* TOFF = -5
* Assing Op
* ID
* Local or Parm Var
40 : LD 3,-2(1)    Load Variable x
* End ID
* Loading Left Hand Side
41 : ST 3,-5(1)    Loading LHS (var x)
* TOFF = -6
* Loading Right Hand Side
* CONST
42 : LDC 3,753(0)Load Integer Const
* End CONST
* TOFF = -5
* Variablex LOC is -2
* Local or Parmaets Var
43 : ST 3,-2(1)    Loading LHS (var x)
* Assing Op
* ID
* Local or Parm Var
44 : LD 3,-3(1)    Load Variable y
* End ID
* Loading Left Hand Side
45 : ST 3,-5(1)    Loading LHS (var y)
* TOFF = -6
* Loading Right Hand Side
* CONST
46 : LDC 3,444(0)Load Integer Const
* End CONST
* TOFF = -5
* Variabley LOC is -3
* Local or Parmaets Var
47 : ST 3,-3(1)    Loading LHS (var y)
* Assing Op
* ID
* Local or Parm Var
48 : LD 3,-4(1)    Load Variable z
* End ID
* Loading Left Hand Side
49 : ST 3,-5(1)    Loading LHS (var z)
* TOFF = -6
* Loading Right Hand Side
* CONST
50 : LDC 3,931(0)Load Integer Const
* End CONST
* TOFF = -5
* Variablez LOC is -4
* Local or Parmaets Var
51 : ST 3,-4(1)    Loading LHS (var z)
* CALL output
52 : ST 1,-5(1) FP in ghost frame for output
* TOFF =-6
* Loading Parms
* TOFF =-7
* Assing Op
* ID
* Local or Parm Var
53 : LD 3,-4(1)    Load Variable z
* End ID
* Loading Left Hand Side
54 : ST 3,-7(1)    Loading LHS (var z)
* TOFF = -8
* Loading Right Hand Side
* Assing Op
* ID
* Local or Parm Var
55 : LD 3,-2(1)    Load Variable x
* End ID
* Loading Left Hand Side
56 : ST 3,-8(1)    Loading LHS (var x)
* TOFF = -9
* Loading Right Hand Side
* ID
* Local or Parm Var
57 : LD 3,-3(1)    Load Variable y
* End ID
* TOFF = -8
58 : LD 4,-8(1)   Loading left into AC2
59 : SUB 3,4,3   ADD -= op
* Variablex LOC is -2
* Local or Parmaets Var
60 : ST 3,-2(1)    Loading LHS (var x)
* TOFF = -7
61 : LD 4,-7(1)   Loading left into AC2
62 : SUB 3,4,3   ADD -= op
* Variablez LOC is -4
* Local or Parmaets Var
63 : ST 3,-4(1)    Loading LHS (var z)
64 : ST 3,-7(1)    Push Param
65 : LDA 1,-5(1)    Ghost Frame become new active frame
66 : LDA 3,1(7)   Return addr in AC
* Func addr: 6
67 : JMP 7,-62(7)    Call output
68 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -5
* CALL output
69 : ST 1,-5(1) FP in ghost frame for output
* TOFF =-6
* Loading Parms
70 : LDA 1,-5(1)    Ghost Frame become new active frame
71 : LDA 3,1(7)   Return addr in AC
* Func addr: 34
72 : JMP 7,-39(7)    Call outnl
73 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -5
* End of Compound 
* TOFF = -2
* add Standard end in case of no return 
74 : LDC 2,0(0)   Set Ret val to 0
75 : LD 3,-1(1) Load Return addr
76 : LD 1,0(1)   Adjust Frame Pointer 
77 : JMP 7,0 (3)  Ret
* END OF FUNC main
*INIT 
0 : JMP 7,77(7)     Jmp to init 
78 : LDA 1,0(0)  set frist frame (end of globals) 
79 : ST 1,0(1)   Store old fp ()
* GLOBLS + STATICS (idk how to do this KEKW)
80 : LDA 3,1(7)  return addr in ac? 
* Main ADDR 39
81 : JMP 7,-43(7)   Jump to main
82 : HALT 0,0,0 DONE
