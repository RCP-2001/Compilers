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
* Left hand side in AC1
* ID
* Local or Parm Var
40 : LD 3,-2(1)    Load Variable x
* End ID
* Storing Left Hand Side
41 : ST 3,-5(1)    Loading LHS (var x)
* TOFF = -6
* Loading Right Hand Side
* CONST
42 : LDC 3,'A'(0)Load Char Const
* End CONST
* TOFF = -5
* Variablex LOC is -2
* Local or Parmaets Var
43 : ST 3,-2(1)    Loading LHS (var x)
* TOFF = -5
* End Assing Op
* Assing Op
* Left hand side in AC1
* ID
* Local or Parm Var
44 : LD 3,-3(1)    Load Variable y
* End ID
* Storing Left Hand Side
45 : ST 3,-5(1)    Loading LHS (var y)
* TOFF = -6
* Loading Right Hand Side
* CONST
46 : LDC 3,'B'(0)Load Char Const
* End CONST
* TOFF = -5
* Variabley LOC is -3
* Local or Parmaets Var
47 : ST 3,-3(1)    Loading LHS (var y)
* TOFF = -5
* End Assing Op
* CALL output
48 : ST 1,-5(1) FP in ghost frame for output
* TOFF =-6
* Loading Parms
* ID
* (ID) TOFF =-7
* Local or Parm Var
49 : LD 3,-2(1)    Load Variable x
50 : ST 3,-7(1)    Push Param
* End ID
51 : LDA 1,-5(1)    Ghost Frame become new active frame
52 : LDA 3,1(7)   Return addr in AC
* Func addr: 28
53 : JMP 7,-26(7)    Call outputc
54 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -5
* CALL output
55 : ST 1,-5(1) FP in ghost frame for output
* TOFF =-6
* Loading Parms
* ID
* (ID) TOFF =-7
* Local or Parm Var
56 : LD 3,-3(1)    Load Variable y
57 : ST 3,-7(1)    Push Param
* End ID
58 : LDA 1,-5(1)    Ghost Frame become new active frame
59 : LDA 3,1(7)   Return addr in AC
* Func addr: 28
60 : JMP 7,-33(7)    Call outputc
61 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -5
* CALL output
62 : ST 1,-5(1) FP in ghost frame for output
* TOFF =-6
* Loading Parms
* TOFF =-7
* Assing Op
* Left hand side in AC1
* ID
* Local or Parm Var
63 : LD 3,-4(1)    Load Variable z
* End ID
* Storing Left Hand Side
64 : ST 3,-7(1)    Loading LHS (var z)
* TOFF = -8
* Loading Right Hand Side
* Assing Op
* Left hand side in AC1
* ID
* Local or Parm Var
65 : LD 3,-2(1)    Load Variable x
* End ID
* Storing Left Hand Side
66 : ST 3,-8(1)    Loading LHS (var x)
* TOFF = -9
* Loading Right Hand Side
* ID
* Local or Parm Var
67 : LD 3,-3(1)    Load Variable y
* End ID
* TOFF = -8
* Variablex LOC is -2
* Local or Parmaets Var
68 : ST 3,-2(1)    Loading LHS (var x)
* TOFF = -8
* End Assing Op
* TOFF = -7
* Variablez LOC is -4
* Local or Parmaets Var
69 : ST 3,-4(1)    Loading LHS (var z)
* TOFF = -7
70 : ST 3,-7(1)    Push Param
* End Assing Op
71 : LDA 1,-5(1)    Ghost Frame become new active frame
72 : LDA 3,1(7)   Return addr in AC
* Func addr: 28
73 : JMP 7,-46(7)    Call outputc
74 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -5
* CALL output
75 : ST 1,-5(1) FP in ghost frame for output
* TOFF =-6
* Loading Parms
* ID
* (ID) TOFF =-7
* Local or Parm Var
76 : LD 3,-2(1)    Load Variable x
77 : ST 3,-7(1)    Push Param
* End ID
78 : LDA 1,-5(1)    Ghost Frame become new active frame
79 : LDA 3,1(7)   Return addr in AC
* Func addr: 28
80 : JMP 7,-53(7)    Call outputc
81 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -5
* CALL output
82 : ST 1,-5(1) FP in ghost frame for output
* TOFF =-6
* Loading Parms
* ID
* (ID) TOFF =-7
* Local or Parm Var
83 : LD 3,-3(1)    Load Variable y
84 : ST 3,-7(1)    Push Param
* End ID
85 : LDA 1,-5(1)    Ghost Frame become new active frame
86 : LDA 3,1(7)   Return addr in AC
* Func addr: 28
87 : JMP 7,-60(7)    Call outputc
88 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -5
* CALL output
89 : ST 1,-5(1) FP in ghost frame for output
* TOFF =-6
* Loading Parms
* ID
* (ID) TOFF =-7
* Local or Parm Var
90 : LD 3,-4(1)    Load Variable z
91 : ST 3,-7(1)    Push Param
* End ID
92 : LDA 1,-5(1)    Ghost Frame become new active frame
93 : LDA 3,1(7)   Return addr in AC
* Func addr: 28
94 : JMP 7,-67(7)    Call outputc
95 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -5
* CALL output
96 : ST 1,-5(1) FP in ghost frame for output
* TOFF =-6
* Loading Parms
97 : LDA 1,-5(1)    Ghost Frame become new active frame
98 : LDA 3,1(7)   Return addr in AC
* Func addr: 34
99 : JMP 7,-66(7)    Call outnl
100 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -5
* End of Compound 
* TOFF = -2
* add Standard end in case of no return 
101 : LDC 2,0(0)   Set Ret val to 0
102 : LD 3,-1(1) Load Return addr
103 : LD 1,0(1)   Adjust Frame Pointer 
104 : JMP 7,0 (3)  Ret
* END OF FUNC main
*INIT 
0 : JMP 7,104(7)     Jmp to init 
105 : LDA 1,0(0)  set frist frame (end of globals) 
106 : ST 1,0(1)   Store old fp ()
* GLOBLS + STATICS (idk how to do this KEKW)
107 : LDA 3,1(7)  return addr in ac? 
* Main ADDR 39
108 : JMP 7,-70(7)   Jump to main
109 : HALT 0,0,0 DONE
