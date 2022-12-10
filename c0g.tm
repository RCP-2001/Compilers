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
39 : LDC 3,7(0)    LOAD SIZE of ARRAY
40 : ST 3,0(0) Save Array Size
* ** ** ** ** ** ** ** ** ** ** ** ** 
* FUNC main
* TOFF = -2
41 : ST  3,-1(1) Store Ret Addr
* COMPOUND
* TOFF = -2
* Assing Op
* Left hand side in AC1
* OP 
* ID
* Global or LocalStatic Var
42 : LD 3,-1(0)    Load Variable x
* End ID
* Loading Left Hand Side
43 : ST 3,-2(1)    Loading LHS (var x)
* TOFF = -3
* CONST
44 : LDC 3,3(0)Load Integer Const
* End CONST
* TOFF = -2
45 : LD 4,-2(1)   Loading left (?] into AC2
* Global or LocalStatic Array
46 : LDA 6,-1(0)     Load address of base
47 : SUB 6,6,3       Compute offset value
48 : LD 3,0(6)   Storing Array Value in AC1
* TOFF = -3
* Storing Left Hand Side
49 : ST 3,-3(1)    Loading LHS (var [)
* TOFF = -4
* Loading Right Hand Side
* CONST
50 : LDC 3,1023(0)Load Integer Const
* End CONST
* TOFF = -3
* Assinging to array Location
51 : ST 3,0(6) Store AC1 in array
* TOFF = -2
* End Assing Op
* CALL output
52 : ST 1,-2(1) FP in ghost frame for output
* TOFF =-3
* Loading Parms
* TOFF =-4
* Assing Op
* Left hand side in AC1
* OP 
* ID
* Global or LocalStatic Var
53 : LD 3,-1(0)    Load Variable x
* End ID
* Loading Left Hand Side
54 : ST 3,-4(1)    Loading LHS (var x)
* TOFF = -5
* CONST
55 : LDC 3,3(0)Load Integer Const
* End CONST
* TOFF = -4
56 : LD 4,-4(1)   Loading left (?] into AC2
* Global or LocalStatic Array
57 : LDA 6,-1(0)     Load address of base
58 : SUB 6,6,3       Compute offset value
59 : LD 3,0(6)   Storing Array Value in AC1
* TOFF = -5
* Storing Left Hand Side
60 : ST 3,-5(1)    Loading LHS (var [)
* TOFF = -6
* Loading Right Hand Side
* TOFF = -5
* INC OPERATOR
61 : LD 4,-5(1)   Loading left into AC2
62 : LDC 3,1(0)   Loading 1 into AC1
63 : ADD 3,4,3   ADD ++ op
* Assinging to array Location
64 : ST 3,0(6) Store AC1 in array
* TOFF = -4
65 : ST 3,-4(1)    Push Param
* End Assing Op
66 : LDA 1,-2(1)    Ghost Frame become new active frame
67 : LDA 3,1(7)   Return addr in AC
* Func addr: 6
68 : JMP 7,-63(7)    Call output
69 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -2
* CALL output
70 : ST 1,-2(1) FP in ghost frame for output
* TOFF =-3
* Loading Parms
71 : LDA 1,-2(1)    Ghost Frame become new active frame
72 : LDA 3,1(7)   Return addr in AC
* Func addr: 34
73 : JMP 7,-40(7)    Call outnl
74 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -2
* CALL output
75 : ST 1,-2(1) FP in ghost frame for output
* TOFF =-3
* Loading Parms
* OP 
* ID
* Global or LocalStatic Var
76 : LD 3,-1(0)    Load Variable x
* End ID
* Loading Left Hand Side
77 : ST 3,-3(1)    Loading LHS (var x)
* TOFF = -4
* CONST
78 : LDC 3,3(0)Load Integer Const
* End CONST
* TOFF = -3
79 : LD 4,-3(1)   Loading left (?] into AC2
* Global or LocalStatic Array
80 : LDA 6,-1(0)     Load address of base
81 : SUB 6,6,3       Compute offset value
82 : LD 3,0(6)   Storing Array Value in AC1
* TOFF = -4
83 : LDA 1,-2(1)    Ghost Frame become new active frame
84 : LDA 3,1(7)   Return addr in AC
* Func addr: 6
85 : JMP 7,-80(7)    Call output
86 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -2
* CALL output
87 : ST 1,-2(1) FP in ghost frame for output
* TOFF =-3
* Loading Parms
88 : LDA 1,-2(1)    Ghost Frame become new active frame
89 : LDA 3,1(7)   Return addr in AC
* Func addr: 34
90 : JMP 7,-57(7)    Call outnl
91 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -2
* CALL output
92 : ST 1,-2(1) FP in ghost frame for output
* TOFF =-3
* Loading Parms
* TOFF =-4
* Assing Op
* Left hand side in AC1
* OP 
* ID
* Global or LocalStatic Var
93 : LD 3,-1(0)    Load Variable x
* End ID
* Loading Left Hand Side
94 : ST 3,-4(1)    Loading LHS (var x)
* TOFF = -5
* CONST
95 : LDC 3,3(0)Load Integer Const
* End CONST
* TOFF = -4
96 : LD 4,-4(1)   Loading left (?] into AC2
* Global or LocalStatic Array
97 : LDA 6,-1(0)     Load address of base
98 : SUB 6,6,3       Compute offset value
99 : LD 3,0(6)   Storing Array Value in AC1
* TOFF = -5
* Storing Left Hand Side
100 : ST 3,-5(1)    Loading LHS (var [)
* TOFF = -6
* Loading Right Hand Side
* TOFF = -5
* DEC OPERATOR
101 : LD 4,-5(1)   Loading left (only?) into AC2
102 : LDC 3,1(0)   Loading 1 into AC1
103 : SUB 3,4,3   SUB -- op
* Assinging to array Location
104 : ST 3,0(6) Store AC1 in array
* TOFF = -4
105 : ST 3,-4(1)    Push Param
* End Assing Op
106 : LDA 1,-2(1)    Ghost Frame become new active frame
107 : LDA 3,1(7)   Return addr in AC
* Func addr: 6
108 : JMP 7,-103(7)    Call output
109 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -2
* CALL output
110 : ST 1,-2(1) FP in ghost frame for output
* TOFF =-3
* Loading Parms
111 : LDA 1,-2(1)    Ghost Frame become new active frame
112 : LDA 3,1(7)   Return addr in AC
* Func addr: 34
113 : JMP 7,-80(7)    Call outnl
114 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -2
* CALL output
115 : ST 1,-2(1) FP in ghost frame for output
* TOFF =-3
* Loading Parms
* OP 
* ID
* Global or LocalStatic Var
116 : LD 3,-1(0)    Load Variable x
* End ID
* Loading Left Hand Side
117 : ST 3,-3(1)    Loading LHS (var x)
* TOFF = -4
* CONST
118 : LDC 3,3(0)Load Integer Const
* End CONST
* TOFF = -3
119 : LD 4,-3(1)   Loading left (?] into AC2
* Global or LocalStatic Array
120 : LDA 6,-1(0)     Load address of base
121 : SUB 6,6,3       Compute offset value
122 : LD 3,0(6)   Storing Array Value in AC1
* TOFF = -4
123 : LDA 1,-2(1)    Ghost Frame become new active frame
124 : LDA 3,1(7)   Return addr in AC
* Func addr: 6
125 : JMP 7,-120(7)    Call output
126 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -2
* CALL output
127 : ST 1,-2(1) FP in ghost frame for output
* TOFF =-3
* Loading Parms
128 : LDA 1,-2(1)    Ghost Frame become new active frame
129 : LDA 3,1(7)   Return addr in AC
* Func addr: 34
130 : JMP 7,-97(7)    Call outnl
131 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -2
* End of Compound 
* TOFF = -2
* add Standard end in case of no return 
132 : LDC 2,0(0)   Set Ret val to 0
133 : LD 3,-1(1) Load Return addr
134 : LD 1,0(1)   Adjust Frame Pointer 
135 : JMP 7,0 (3)  Ret
* END OF FUNC main
*INIT 
0 : JMP 7,135(7)     Jmp to init 
136 : LDA 1,-8(0)  set frist frame (end of globals) 
137 : ST 1,0(1)   Store old fp ()
* GLOBLS + STATICS (idk how to do this KEKW)
138 : LDA 3,1(7)  return addr in ac? 
* Main ADDR 41
139 : JMP 7,-99(7)   Jump to main
140 : HALT 0,0,0 DONE
