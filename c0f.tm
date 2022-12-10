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
40 : LDC 3,7(0)    LOAD SIZE of ARRAY
41 : ST 3,-2(1) Save Array Size
* Assing Op
* Left hand side in AC1
* OP 
* ID
* Local or Parm Var
42 : LD 3,-3(1)    Load Variable x
* End ID
* Loading Left Hand Side
43 : ST 3,-10(1)    Loading LHS (var x)
* TOFF = -11
* CONST
44 : LDC 3,3(0)Load Integer Const
* End CONST
* TOFF = -10
45 : LD 4,-10(1)   Loading left (?] into AC2
* Loacl Array
46 : LDA 6,-3(1)     Load address of base
47 : SUB 6,6,3       Compute offset value
48 : LD 3,0(6)   Storing Array Value in AC1
* TOFF = -11
* Storing Left Hand Side
49 : ST 3,-11(1)    Loading LHS (var [)
* TOFF = -12
* Loading Right Hand Side
* CONST
50 : LDC 3,1023(0)Load Integer Const
* End CONST
* TOFF = -11
* Assinging to array Location
51 : ST 3,0(6) Store AC1 in array
* TOFF = -10
* End Assing Op
* CALL output
52 : ST 1,-10(1) FP in ghost frame for output
* TOFF =-11
* Loading Parms
* TOFF =-12
* Assing Op
* Left hand side in AC1
* OP 
* ID
* Local or Parm Var
53 : LD 3,-3(1)    Load Variable x
* End ID
* Loading Left Hand Side
54 : ST 3,-12(1)    Loading LHS (var x)
* TOFF = -13
* CONST
55 : LDC 3,3(0)Load Integer Const
* End CONST
* TOFF = -12
56 : LD 4,-12(1)   Loading left (?] into AC2
* Loacl Array
57 : LDA 6,-3(1)     Load address of base
58 : SUB 6,6,3       Compute offset value
59 : LD 3,0(6)   Storing Array Value in AC1
* TOFF = -13
* Storing Left Hand Side
60 : ST 3,-13(1)    Loading LHS (var [)
* TOFF = -14
* Loading Right Hand Side
* TOFF = -13
* INC OPERATOR
61 : LD 4,-13(1)   Loading left into AC2
62 : LDC 3,1(0)   Loading 1 into AC1
63 : ADD 3,4,3   ADD ++ op
* Assinging to array Location
64 : ST 3,0(6) Store AC1 in array
* TOFF = -12
65 : ST 3,-12(1)    Push Param
* End Assing Op
66 : LDA 1,-10(1)    Ghost Frame become new active frame
67 : LDA 3,1(7)   Return addr in AC
* Func addr: 6
68 : JMP 7,-63(7)    Call output
69 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -10
* CALL output
70 : ST 1,-10(1) FP in ghost frame for output
* TOFF =-11
* Loading Parms
71 : LDA 1,-10(1)    Ghost Frame become new active frame
72 : LDA 3,1(7)   Return addr in AC
* Func addr: 34
73 : JMP 7,-40(7)    Call outnl
74 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -10
* CALL output
75 : ST 1,-10(1) FP in ghost frame for output
* TOFF =-11
* Loading Parms
* OP 
* TOFF =-12
* ID
* Local or Parm Var
76 : LD 3,-3(1)    Load Variable x
* End ID
* Loading Left Hand Side
77 : ST 3,-12(1)    Loading LHS (var x)
* TOFF = -13
* CONST
78 : LDC 3,3(0)Load Integer Const
* End CONST
* TOFF = -12
79 : LD 4,-12(1)   Loading left (?] into AC2
* Loacl Array
80 : LDA 6,-3(1)     Load address of base
81 : SUB 6,6,3       Compute offset value
82 : LD 3,0(6)   Storing Array Value in AC1
83 : ST 3,-12(1)    Push Param
* TOFF = -13
84 : LDA 1,-10(1)    Ghost Frame become new active frame
85 : LDA 3,1(7)   Return addr in AC
* Func addr: 6
86 : JMP 7,-81(7)    Call output
87 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -10
* CALL output
88 : ST 1,-10(1) FP in ghost frame for output
* TOFF =-11
* Loading Parms
89 : LDA 1,-10(1)    Ghost Frame become new active frame
90 : LDA 3,1(7)   Return addr in AC
* Func addr: 34
91 : JMP 7,-58(7)    Call outnl
92 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -10
* CALL output
93 : ST 1,-10(1) FP in ghost frame for output
* TOFF =-11
* Loading Parms
* TOFF =-12
* Assing Op
* Left hand side in AC1
* OP 
* ID
* Local or Parm Var
94 : LD 3,-3(1)    Load Variable x
* End ID
* Loading Left Hand Side
95 : ST 3,-12(1)    Loading LHS (var x)
* TOFF = -13
* CONST
96 : LDC 3,3(0)Load Integer Const
* End CONST
* TOFF = -12
97 : LD 4,-12(1)   Loading left (?] into AC2
* Loacl Array
98 : LDA 6,-3(1)     Load address of base
99 : SUB 6,6,3       Compute offset value
100 : LD 3,0(6)   Storing Array Value in AC1
* TOFF = -13
* Storing Left Hand Side
101 : ST 3,-13(1)    Loading LHS (var [)
* TOFF = -14
* Loading Right Hand Side
* TOFF = -13
* DEC OPERATOR
102 : LD 4,-13(1)   Loading left (only?) into AC2
103 : LDC 3,1(0)   Loading 1 into AC1
104 : SUB 3,4,3   SUB -- op
* Assinging to array Location
105 : ST 3,0(6) Store AC1 in array
* TOFF = -12
106 : ST 3,-12(1)    Push Param
* End Assing Op
107 : LDA 1,-10(1)    Ghost Frame become new active frame
108 : LDA 3,1(7)   Return addr in AC
* Func addr: 6
109 : JMP 7,-104(7)    Call output
110 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -10
* CALL output
111 : ST 1,-10(1) FP in ghost frame for output
* TOFF =-11
* Loading Parms
112 : LDA 1,-10(1)    Ghost Frame become new active frame
113 : LDA 3,1(7)   Return addr in AC
* Func addr: 34
114 : JMP 7,-81(7)    Call outnl
115 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -10
* CALL output
116 : ST 1,-10(1) FP in ghost frame for output
* TOFF =-11
* Loading Parms
* OP 
* TOFF =-12
* ID
* Local or Parm Var
117 : LD 3,-3(1)    Load Variable x
* End ID
* Loading Left Hand Side
118 : ST 3,-12(1)    Loading LHS (var x)
* TOFF = -13
* CONST
119 : LDC 3,3(0)Load Integer Const
* End CONST
* TOFF = -12
120 : LD 4,-12(1)   Loading left (?] into AC2
* Loacl Array
121 : LDA 6,-3(1)     Load address of base
122 : SUB 6,6,3       Compute offset value
123 : LD 3,0(6)   Storing Array Value in AC1
124 : ST 3,-12(1)    Push Param
* TOFF = -13
125 : LDA 1,-10(1)    Ghost Frame become new active frame
126 : LDA 3,1(7)   Return addr in AC
* Func addr: 6
127 : JMP 7,-122(7)    Call output
128 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -10
* CALL output
129 : ST 1,-10(1) FP in ghost frame for output
* TOFF =-11
* Loading Parms
130 : LDA 1,-10(1)    Ghost Frame become new active frame
131 : LDA 3,1(7)   Return addr in AC
* Func addr: 34
132 : JMP 7,-99(7)    Call outnl
133 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -10
* End of Compound 
* TOFF = -2
* add Standard end in case of no return 
134 : LDC 2,0(0)   Set Ret val to 0
135 : LD 3,-1(1) Load Return addr
136 : LD 1,0(1)   Adjust Frame Pointer 
137 : JMP 7,0 (3)  Ret
* END OF FUNC main
*INIT 
0 : JMP 7,137(7)     Jmp to init 
138 : LDA 1,0(0)  set frist frame (end of globals) 
139 : ST 1,0(1)   Store old fp ()
* GLOBLS + STATICS (idk how to do this KEKW)
140 : LDA 3,1(7)  return addr in ac? 
* Main ADDR 39
141 : JMP 7,-103(7)   Jump to main
142 : HALT 0,0,0 DONE
