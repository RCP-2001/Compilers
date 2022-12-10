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
* TOFF = -10
* Assing Op
* OP 
* ID
* Local or Parm Var
40 : LD 3,-3(1)    Load Variable x
* End ID
* Loading Left Hand Side
41 : ST 3,-10(1)    Loading LHS (var x)
* TOFF = -11
* CONST
42 : LDC 3,3(0)Load Integer Const
* End CONST
* TOFF = -10
* TOFF = -11
* Loading Left Hand Side
43 : ST 3,-11(1)    Loading LHS (var [)
* TOFF = -12
* Loading Right Hand Side
* CONST
44 : LDC 3,1023(0)Load Integer Const
* End CONST
* TOFF = -10
* Variable[ LOC is 0
* Local or Parmaets Var
45 : ST 3,0(1)    Loading LHS (var [)
* CALL output
46 : ST 1,-10(1) FP in ghost frame for output
* TOFF =-11
* Loading Parms
* TOFF =-12
* Assing Op
* OP 
* ID
* Local or Parm Var
47 : LD 3,-3(1)    Load Variable x
* End ID
* Loading Left Hand Side
48 : ST 3,-12(1)    Loading LHS (var x)
* TOFF = -13
* CONST
49 : LDC 3,3(0)Load Integer Const
* End CONST
* TOFF = -12
* TOFF = -13
* Loading Left Hand Side
50 : ST 3,-13(1)    Loading LHS (var [)
* TOFF = -14
* Loading Right Hand Side
* TOFF = -12
* INC OPERATOR
51 : LD 4,-12(1)   Loading left into AC2
52 : LDC 3,1(0)   Loading 1 into AC1
53 : ADD 3,4,3   ADD ++ op
* Variable[ LOC is 0
* Local or Parmaets Var
54 : ST 3,0(1)    Loading LHS (var [)
55 : ST 3,-12(1)    Push Param
56 : LDA 1,-10(1)    Ghost Frame become new active frame
57 : LDA 3,1(7)   Return addr in AC
* Func addr: 6
58 : JMP 7,-53(7)    Call output
59 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -10
* CALL output
60 : ST 1,-10(1) FP in ghost frame for output
* TOFF =-11
* Loading Parms
61 : LDA 1,-10(1)    Ghost Frame become new active frame
62 : LDA 3,1(7)   Return addr in AC
* Func addr: 34
63 : JMP 7,-30(7)    Call outnl
64 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -10
* CALL output
65 : ST 1,-10(1) FP in ghost frame for output
* TOFF =-11
* Loading Parms
* OP 
* ID
* Local or Parm Var
66 : LD 3,-3(1)    Load Variable x
* End ID
* Loading Left Hand Side
67 : ST 3,-11(1)    Loading LHS (var x)
* TOFF = -12
* CONST
68 : LDC 3,3(0)Load Integer Const
* End CONST
* TOFF = -11
* TOFF = -12
69 : LDA 1,-10(1)    Ghost Frame become new active frame
70 : LDA 3,1(7)   Return addr in AC
* Func addr: 6
71 : JMP 7,-66(7)    Call output
72 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -10
* CALL output
73 : ST 1,-10(1) FP in ghost frame for output
* TOFF =-11
* Loading Parms
74 : LDA 1,-10(1)    Ghost Frame become new active frame
75 : LDA 3,1(7)   Return addr in AC
* Func addr: 34
76 : JMP 7,-43(7)    Call outnl
77 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -10
* CALL output
78 : ST 1,-10(1) FP in ghost frame for output
* TOFF =-11
* Loading Parms
* TOFF =-12
* Assing Op
* OP 
* ID
* Local or Parm Var
79 : LD 3,-3(1)    Load Variable x
* End ID
* Loading Left Hand Side
80 : ST 3,-12(1)    Loading LHS (var x)
* TOFF = -13
* CONST
81 : LDC 3,3(0)Load Integer Const
* End CONST
* TOFF = -12
* TOFF = -13
* Loading Left Hand Side
82 : ST 3,-13(1)    Loading LHS (var [)
* TOFF = -14
* Loading Right Hand Side
* TOFF = -12
* DEC OPERATOR
83 : LD 4,-12(1)   Loading left (only?) into AC2
84 : LDC 3,1(0)   Loading 1 into AC1
85 : SUB 3,4,3   SUB -- op
* Variable[ LOC is 0
* Local or Parmaets Var
86 : ST 3,0(1)    Loading LHS (var [)
87 : ST 3,-12(1)    Push Param
88 : LDA 1,-10(1)    Ghost Frame become new active frame
89 : LDA 3,1(7)   Return addr in AC
* Func addr: 6
90 : JMP 7,-85(7)    Call output
91 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -10
* CALL output
92 : ST 1,-10(1) FP in ghost frame for output
* TOFF =-11
* Loading Parms
93 : LDA 1,-10(1)    Ghost Frame become new active frame
94 : LDA 3,1(7)   Return addr in AC
* Func addr: 34
95 : JMP 7,-62(7)    Call outnl
96 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -10
* CALL output
97 : ST 1,-10(1) FP in ghost frame for output
* TOFF =-11
* Loading Parms
* OP 
* ID
* Local or Parm Var
98 : LD 3,-3(1)    Load Variable x
* End ID
* Loading Left Hand Side
99 : ST 3,-11(1)    Loading LHS (var x)
* TOFF = -12
* CONST
100 : LDC 3,3(0)Load Integer Const
* End CONST
* TOFF = -11
* TOFF = -12
101 : LDA 1,-10(1)    Ghost Frame become new active frame
102 : LDA 3,1(7)   Return addr in AC
* Func addr: 6
103 : JMP 7,-98(7)    Call output
104 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -10
* CALL output
105 : ST 1,-10(1) FP in ghost frame for output
* TOFF =-11
* Loading Parms
106 : LDA 1,-10(1)    Ghost Frame become new active frame
107 : LDA 3,1(7)   Return addr in AC
* Func addr: 34
108 : JMP 7,-75(7)    Call outnl
109 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -10
* End of Compound 
* TOFF = -2
* add Standard end in case of no return 
110 : LDC 2,0(0)   Set Ret val to 0
111 : LD 3,-1(1) Load Return addr
112 : LD 1,0(1)   Adjust Frame Pointer 
113 : JMP 7,0 (3)  Ret
* END OF FUNC main
*INIT 
0 : JMP 7,113(7)     Jmp to init 
114 : LDA 1,0(0)  set frist frame (end of globals) 
115 : ST 1,0(1)   Store old fp ()
* GLOBLS + STATICS (idk how to do this KEKW)
116 : LDA 3,1(7)  return addr in ac? 
* Main ADDR 39
117 : JMP 7,-79(7)   Jump to main
118 : HALT 0,0,0 DONE
