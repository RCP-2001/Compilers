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
* FUNC dog
* TOFF = -3
39 : ST  3,-1(1) Store Ret Addr
* COMPOUND
* TOFF = -3
* CALL output
40 : ST 1,-3(1) FP in ghost frame for output
* TOFF =-4
* Loading Parms
* TOFF =-5
* Assing Op
* Left hand side in AC1
* OP 
* ID
* Local or Parm Var
41 : LD 3,-2(1)    Load Variable x
* End ID
* Loading Left Hand Side
42 : ST 3,-5(1)    Loading LHS (var x)
* TOFF = -6
* CONST
43 : LDC 3,3(0)Load Integer Const
* End CONST
* TOFF = -5
44 : LD 4,-5(1)   Loading left (?] into AC2
* Loacl Array
45 : LDA 6,-2(1)     Load address of base
46 : SUB 6,6,3       Compute offset value
47 : LD 3,0(6)   Storing Array Value in AC1
* TOFF = -6
* Storing Left Hand Side
48 : ST 3,-6(1)    Loading LHS (var [)
* TOFF = -7
* Loading Right Hand Side
* TOFF = -6
* INC OPERATOR
49 : LD 4,-6(1)   Loading left into AC2
50 : LDC 3,1(0)   Loading 1 into AC1
51 : ADD 3,4,3   ADD ++ op
* Assinging to array Location
52 : ST 3,0(6) Store AC1 in array
* TOFF = -5
53 : ST 3,-5(1)    Push Param
* End Assing Op
54 : LDA 1,-3(1)    Ghost Frame become new active frame
55 : LDA 3,1(7)   Return addr in AC
* Func addr: 6
56 : JMP 7,-51(7)    Call output
57 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -3
* CALL output
58 : ST 1,-3(1) FP in ghost frame for output
* TOFF =-4
* Loading Parms
59 : LDA 1,-3(1)    Ghost Frame become new active frame
60 : LDA 3,1(7)   Return addr in AC
* Func addr: 34
61 : JMP 7,-28(7)    Call outnl
62 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -3
* CALL output
63 : ST 1,-3(1) FP in ghost frame for output
* TOFF =-4
* Loading Parms
* OP 
* ID
* Local or Parm Var
64 : LD 3,-2(1)    Load Variable x
* End ID
* Loading Left Hand Side
65 : ST 3,-4(1)    Loading LHS (var x)
* TOFF = -5
* CONST
66 : LDC 3,3(0)Load Integer Const
* End CONST
* TOFF = -4
67 : LD 4,-4(1)   Loading left (?] into AC2
* Loacl Array
68 : LDA 6,-2(1)     Load address of base
69 : SUB 6,6,3       Compute offset value
70 : LD 3,0(6)   Storing Array Value in AC1
* TOFF = -5
71 : LDA 1,-3(1)    Ghost Frame become new active frame
72 : LDA 3,1(7)   Return addr in AC
* Func addr: 6
73 : JMP 7,-68(7)    Call output
74 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -3
* CALL output
75 : ST 1,-3(1) FP in ghost frame for output
* TOFF =-4
* Loading Parms
76 : LDA 1,-3(1)    Ghost Frame become new active frame
77 : LDA 3,1(7)   Return addr in AC
* Func addr: 34
78 : JMP 7,-45(7)    Call outnl
79 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -3
* CALL output
80 : ST 1,-3(1) FP in ghost frame for output
* TOFF =-4
* Loading Parms
* TOFF =-5
* Assing Op
* Left hand side in AC1
* OP 
* ID
* Local or Parm Var
81 : LD 3,-2(1)    Load Variable x
* End ID
* Loading Left Hand Side
82 : ST 3,-5(1)    Loading LHS (var x)
* TOFF = -6
* CONST
83 : LDC 3,3(0)Load Integer Const
* End CONST
* TOFF = -5
84 : LD 4,-5(1)   Loading left (?] into AC2
* Loacl Array
85 : LDA 6,-2(1)     Load address of base
86 : SUB 6,6,3       Compute offset value
87 : LD 3,0(6)   Storing Array Value in AC1
* TOFF = -6
* Storing Left Hand Side
88 : ST 3,-6(1)    Loading LHS (var [)
* TOFF = -7
* Loading Right Hand Side
* TOFF = -6
* DEC OPERATOR
89 : LD 4,-6(1)   Loading left (only?) into AC2
90 : LDC 3,1(0)   Loading 1 into AC1
91 : SUB 3,4,3   SUB -- op
* Assinging to array Location
92 : ST 3,0(6) Store AC1 in array
* TOFF = -5
93 : ST 3,-5(1)    Push Param
* End Assing Op
94 : LDA 1,-3(1)    Ghost Frame become new active frame
95 : LDA 3,1(7)   Return addr in AC
* Func addr: 6
96 : JMP 7,-91(7)    Call output
97 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -3
* CALL output
98 : ST 1,-3(1) FP in ghost frame for output
* TOFF =-4
* Loading Parms
99 : LDA 1,-3(1)    Ghost Frame become new active frame
100 : LDA 3,1(7)   Return addr in AC
* Func addr: 34
101 : JMP 7,-68(7)    Call outnl
102 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -3
* CALL output
103 : ST 1,-3(1) FP in ghost frame for output
* TOFF =-4
* Loading Parms
* OP 
* ID
* Local or Parm Var
104 : LD 3,-2(1)    Load Variable x
* End ID
* Loading Left Hand Side
105 : ST 3,-4(1)    Loading LHS (var x)
* TOFF = -5
* CONST
106 : LDC 3,3(0)Load Integer Const
* End CONST
* TOFF = -4
107 : LD 4,-4(1)   Loading left (?] into AC2
* Loacl Array
108 : LDA 6,-2(1)     Load address of base
109 : SUB 6,6,3       Compute offset value
110 : LD 3,0(6)   Storing Array Value in AC1
* TOFF = -5
111 : LDA 1,-3(1)    Ghost Frame become new active frame
112 : LDA 3,1(7)   Return addr in AC
* Func addr: 6
113 : JMP 7,-108(7)    Call output
114 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -3
* CALL output
115 : ST 1,-3(1) FP in ghost frame for output
* TOFF =-4
* Loading Parms
116 : LDA 1,-3(1)    Ghost Frame become new active frame
117 : LDA 3,1(7)   Return addr in AC
* Func addr: 34
118 : JMP 7,-85(7)    Call outnl
119 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -3
* End of Compound 
* TOFF = -3
* add Standard end in case of no return 
120 : LDC 2,0(0)   Set Ret val to 0
121 : LD 3,-1(1) Load Return addr
122 : LD 1,0(1)   Adjust Frame Pointer 
123 : JMP 7,0 (3)  Ret
* END OF FUNC dog
* ** ** ** ** ** ** ** ** ** ** ** ** 
* FUNC main
* TOFF = -2
124 : ST  3,-1(1) Store Ret Addr
* COMPOUND
* TOFF = -10
125 : LDC 3,7(0)    LOAD SIZE of ARRAY
126 : ST 3,-2(1) Save Array Size
* Assing Op
* Left hand side in AC1
* OP 
* ID
* Local or Parm Var
127 : LD 3,-3(1)    Load Variable x
* End ID
* Loading Left Hand Side
128 : ST 3,-10(1)    Loading LHS (var x)
* TOFF = -11
* CONST
129 : LDC 3,3(0)Load Integer Const
* End CONST
* TOFF = -10
130 : LD 4,-10(1)   Loading left (?] into AC2
* Loacl Array
131 : LDA 6,-3(1)     Load address of base
132 : SUB 6,6,3       Compute offset value
133 : LD 3,0(6)   Storing Array Value in AC1
* TOFF = -11
* Storing Left Hand Side
134 : ST 3,-11(1)    Loading LHS (var [)
* TOFF = -12
* Loading Right Hand Side
* CONST
135 : LDC 3,1023(0)Load Integer Const
* End CONST
* TOFF = -11
* Assinging to array Location
136 : ST 3,0(6) Store AC1 in array
* TOFF = -10
* End Assing Op
* CALL output
137 : ST 1,-10(1) FP in ghost frame for output
* TOFF =-11
* Loading Parms
* OP 
* ID
* Local or Parm Var
138 : LD 3,-3(1)    Load Variable x
* End ID
* Loading Left Hand Side
139 : ST 3,-11(1)    Loading LHS (var x)
* TOFF = -12
* CONST
140 : LDC 3,3(0)Load Integer Const
* End CONST
* TOFF = -11
141 : LD 4,-11(1)   Loading left (?] into AC2
* Loacl Array
142 : LDA 6,-3(1)     Load address of base
143 : SUB 6,6,3       Compute offset value
144 : LD 3,0(6)   Storing Array Value in AC1
* TOFF = -12
145 : LDA 1,-10(1)    Ghost Frame become new active frame
146 : LDA 3,1(7)   Return addr in AC
* Func addr: 6
147 : JMP 7,-142(7)    Call output
148 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -10
* CALL output
149 : ST 1,-10(1) FP in ghost frame for output
* TOFF =-11
* Loading Parms
* ID
* (ID) TOFF =-12
* Local or Parm Var
150 : LD 3,-3(1)    Load Variable x
151 : ST 3,-12(1)    Push Param
* End ID
152 : LDA 1,-10(1)    Ghost Frame become new active frame
153 : LDA 3,1(7)   Return addr in AC
* Func addr: 39
154 : JMP 7,-116(7)    Call dog
155 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -10
* CALL output
156 : ST 1,-10(1) FP in ghost frame for output
* TOFF =-11
* Loading Parms
* OP 
* ID
* Local or Parm Var
157 : LD 3,-3(1)    Load Variable x
* End ID
* Loading Left Hand Side
158 : ST 3,-11(1)    Loading LHS (var x)
* TOFF = -12
* CONST
159 : LDC 3,3(0)Load Integer Const
* End CONST
* TOFF = -11
160 : LD 4,-11(1)   Loading left (?] into AC2
* Loacl Array
161 : LDA 6,-3(1)     Load address of base
162 : SUB 6,6,3       Compute offset value
163 : LD 3,0(6)   Storing Array Value in AC1
* TOFF = -12
164 : LDA 1,-10(1)    Ghost Frame become new active frame
165 : LDA 3,1(7)   Return addr in AC
* Func addr: 6
166 : JMP 7,-161(7)    Call output
167 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -10
* End of Compound 
* TOFF = -2
* add Standard end in case of no return 
168 : LDC 2,0(0)   Set Ret val to 0
169 : LD 3,-1(1) Load Return addr
170 : LD 1,0(1)   Adjust Frame Pointer 
171 : JMP 7,0 (3)  Ret
* END OF FUNC main
*INIT 
0 : JMP 7,171(7)     Jmp to init 
172 : LDA 1,0(0)  set frist frame (end of globals) 
173 : ST 1,0(1)   Store old fp ()
* GLOBLS + STATICS (idk how to do this KEKW)
174 : LDA 3,1(7)  return addr in ac? 
* Main ADDR 124
175 : JMP 7,-52(7)   Jump to main
176 : HALT 0,0,0 DONE
