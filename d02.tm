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
* TOFF = 0
39 : ST  3,-1(1) Store Ret Addr
* COMPOUND
* TOFF = 0
* Assing Op
* Left hand side in AC1
* ID
* Local or Parm Var
40 : LD 3,0(1)    Load Variable x
* End ID
* Storing Left Hand Side
41 : ST 3,0(1)    Loading LHS (var x)
* TOFF = -1
* Loading Right Hand Side
* CONST
42 : LDC 3,755(0)Load Integer Const
* End CONST
* TOFF = 0
* Variablex LOC is 0
* Local or Parmaets Var
43 : ST 3,0(1)    Loading LHS (var x)
* TOFF = 0
* End Assing Op
* Assing Op
* Left hand side in AC1
* ID
* Local or Parm Var
44 : LD 3,0(1)    Load Variable y
* End ID
* Storing Left Hand Side
45 : ST 3,0(1)    Loading LHS (var y)
* TOFF = -1
* Loading Right Hand Side
* CONST
46 : LDC 3,88(0)Load Integer Const
* End CONST
* TOFF = 0
* Variabley LOC is 0
* Local or Parmaets Var
47 : ST 3,0(1)    Loading LHS (var y)
* TOFF = 0
* End Assing Op
* Assing Op
* Left hand side in AC1
* ID
* Local or Parm Var
48 : LD 3,0(1)    Load Variable z
* End ID
* Storing Left Hand Side
49 : ST 3,0(1)    Loading LHS (var z)
* TOFF = -1
* Loading Right Hand Side
* CONST
50 : LDC 3,3(0)Load Integer Const
* End CONST
* TOFF = 0
* Variablez LOC is 0
* Local or Parmaets Var
51 : ST 3,0(1)    Loading LHS (var z)
* TOFF = 0
* End Assing Op
* CALL output
52 : ST 1,0(1) FP in ghost frame for output
* TOFF =-1
* Loading Parms
* TOFF =-2
* OP 
* CONST
53 : LDC 3,755(0)Load Integer Const
* End CONST
* Loading Left Hand Side
54 : ST 3,-2(1)    Loading LHS (var 755)
* TOFF = -3
* OP 
* CONST
55 : LDC 3,88(0)Load Integer Const
* End CONST
* Loading Left Hand Side
56 : ST 3,-3(1)    Loading LHS (var 88)
* TOFF = -4
* CONST
57 : LDC 3,3(0)Load Integer Const
* End CONST
* TOFF = -3
58 : LD 4,-3(1)   Loading left into AC2
59 : MUL 3,4,3   MUL * op
60 : ST 3,-3(1)   Storing Result
* TOFF = -4
* TOFF = -2
61 : LD 4,-2(1)   Loading left into AC2
62 : ADD 3,4,3   ADD + op
63 : ST 3,-2(1)   Storing Result
* TOFF = -3
64 : ST 3,-3(1)    Push Param
65 : LDA 1,0(1)    Ghost Frame become new active frame
66 : LDA 3,1(7)   Return addr in AC
* Func addr: 6
67 : JMP 7,-62(7)    Call output
68 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = 0
* CALL output
69 : ST 1,0(1) FP in ghost frame for output
* TOFF =-1
* Loading Parms
* TOFF =-2
* OP 
* OP 
* CONST
70 : LDC 3,755(0)Load Integer Const
* End CONST
* Loading Left Hand Side
71 : ST 3,-2(1)    Loading LHS (var 755)
* TOFF = -3
* CONST
72 : LDC 3,88(0)Load Integer Const
* End CONST
* TOFF = -2
73 : LD 4,-2(1)   Loading left into AC2
74 : MUL 3,4,3   MUL * op
75 : ST 3,-2(1)   Storing Result
* TOFF = -3
* Loading Left Hand Side
76 : ST 3,-3(1)    Loading LHS (var *)
* TOFF = -4
* CONST
77 : LDC 3,3(0)Load Integer Const
* End CONST
* TOFF = -2
78 : LD 4,-2(1)   Loading left into AC2
79 : ADD 3,4,3   ADD + op
80 : ST 3,-2(1)   Storing Result
* TOFF = -3
81 : ST 3,-3(1)    Push Param
82 : LDA 1,0(1)    Ghost Frame become new active frame
83 : LDA 3,1(7)   Return addr in AC
* Func addr: 6
84 : JMP 7,-79(7)    Call output
85 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = 0
* CALL output
86 : ST 1,0(1) FP in ghost frame for output
* TOFF =-1
* Loading Parms
* TOFF =-2
* OP 
* OP 
* CONST
87 : LDC 3,755(0)Load Integer Const
* End CONST
* Loading Left Hand Side
88 : ST 3,-2(1)    Loading LHS (var 755)
* TOFF = -3
* CONST
89 : LDC 3,88(0)Load Integer Const
* End CONST
* TOFF = -2
90 : LD 4,-2(1)   Loading left into AC2
91 : SUB 3,4,3   SUB - op
92 : ST 3,-2(1)   Storing Result
* TOFF = -3
* Loading Left Hand Side
93 : ST 3,-3(1)    Loading LHS (var -)
* TOFF = -4
* CONST
94 : LDC 3,3(0)Load Integer Const
* End CONST
* TOFF = -2
95 : LD 4,-2(1)   Loading left into AC2
96 : SUB 3,4,3   SUB - op
97 : ST 3,-2(1)   Storing Result
* TOFF = -3
98 : ST 3,-3(1)    Push Param
99 : LDA 1,0(1)    Ghost Frame become new active frame
100 : LDA 3,1(7)   Return addr in AC
* Func addr: 6
101 : JMP 7,-96(7)    Call output
102 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = 0
* CALL output
103 : ST 1,0(1) FP in ghost frame for output
* TOFF =-1
* Loading Parms
* TOFF =-2
* OP 
* OP 
* CONST
104 : LDC 3,755(0)Load Integer Const
* End CONST
* Loading Left Hand Side
105 : ST 3,-2(1)    Loading LHS (var 755)
* TOFF = -3
* CONST
106 : LDC 3,88(0)Load Integer Const
* End CONST
* TOFF = -2
107 : LD 4,-2(1)   Loading left into AC2
108 : DIV 3,4,3   DIV / op
109 : ST 3,-2(1)   Storing Result
* TOFF = -3
* Loading Left Hand Side
110 : ST 3,-3(1)    Loading LHS (var /)
* TOFF = -4
* CONST
111 : LDC 3,3(0)Load Integer Const
* End CONST
* TOFF = -2
112 : LD 4,-2(1)   Loading left into AC2
113 : DIV 3,4,3   DIV / op
114 : ST 3,-2(1)   Storing Result
* TOFF = -3
115 : ST 3,-3(1)    Push Param
116 : LDA 1,0(1)    Ghost Frame become new active frame
117 : LDA 3,1(7)   Return addr in AC
* Func addr: 6
118 : JMP 7,-113(7)    Call output
119 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = 0
* CALL output
120 : ST 1,0(1) FP in ghost frame for output
* TOFF =-1
* Loading Parms
* TOFF =-2
* OP 
* OP 
* CONST
121 : LDC 3,755(0)Load Integer Const
* End CONST
* Loading Left Hand Side
122 : ST 3,-2(1)    Loading LHS (var 755)
* TOFF = -3
* CONST
123 : LDC 3,88(0)Load Integer Const
* End CONST
* TOFF = -2
124 : LD 4,-2(1)   Loading left into AC2
125 : MUL 3,4,3   MUL * op
126 : ST 3,-2(1)   Storing Result
* TOFF = -3
* Loading Left Hand Side
127 : ST 3,-3(1)    Loading LHS (var *)
* TOFF = -4
* OP 
* CONST
128 : LDC 3,3(0)Load Integer Const
* End CONST
* Loading Left Hand Side
129 : ST 3,-4(1)    Loading LHS (var 3)
* TOFF = -5
* CONST
130 : LDC 3,3(0)Load Integer Const
* End CONST
* TOFF = -4
131 : LD 4,-4(1)   Loading left into AC2
132 : MUL 3,4,3   MUL * op
133 : ST 3,-4(1)   Storing Result
* TOFF = -5
* TOFF = -2
134 : LD 4,-2(1)   Loading left into AC2
135 : ADD 3,4,3   ADD + op
136 : ST 3,-2(1)   Storing Result
* TOFF = -3
137 : ST 3,-3(1)    Push Param
138 : LDA 1,0(1)    Ghost Frame become new active frame
139 : LDA 3,1(7)   Return addr in AC
* Func addr: 6
140 : JMP 7,-135(7)    Call output
141 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = 0
* CALL output
142 : ST 1,0(1) FP in ghost frame for output
* TOFF =-1
* Loading Parms
* TOFF =-2
* OP 
* OP 
* CONST
143 : LDC 3,755(0)Load Integer Const
* End CONST
* Loading Left Hand Side
144 : ST 3,-2(1)    Loading LHS (var 755)
* TOFF = -3
* CONST
145 : LDC 3,88(0)Load Integer Const
* End CONST
* TOFF = -2
146 : LD 4,-2(1)   Loading left into AC2
147 : MOD 3,4,3   MOD %% op
148 : ST 3,-2(1)   Storing Result
* TOFF = -3
* Loading Left Hand Side
149 : ST 3,-3(1)    Loading LHS (var %)
* TOFF = -4
* CONST
150 : LDC 3,3(0)Load Integer Const
* End CONST
* TOFF = -2
151 : LD 4,-2(1)   Loading left into AC2
152 : MOD 3,4,3   MOD %% op
153 : ST 3,-2(1)   Storing Result
* TOFF = -3
154 : ST 3,-3(1)    Push Param
155 : LDA 1,0(1)    Ghost Frame become new active frame
156 : LDA 3,1(7)   Return addr in AC
* Func addr: 6
157 : JMP 7,-152(7)    Call output
158 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = 0
* CALL output
159 : ST 1,0(1) FP in ghost frame for output
* TOFF =-1
* Loading Parms
* TOFF =-2
* OP 
* OP 
* CONST
160 : LDC 3,755(0)Load Integer Const
* End CONST
* Loading Left Hand Side
161 : ST 3,-2(1)    Loading LHS (var 755)
* TOFF = -3
* TOFF = -2
162 : LD 4,-2(1)   Loading left (only opperand?) into AC2
163 : NEG 3,4,3   NEG chsign op
164 : ST 3,-2(1)   Storing Result
* TOFF = -3
* Loading Left Hand Side
165 : ST 3,-3(1)    Loading LHS (var chsign)
* TOFF = -4
* OP 
* CONST
166 : LDC 3,88(0)Load Integer Const
* End CONST
* Loading Left Hand Side
167 : ST 3,-4(1)    Loading LHS (var 88)
* TOFF = -5
* CONST
168 : LDC 3,3(0)Load Integer Const
* End CONST
* TOFF = -4
169 : LD 4,-4(1)   Loading left into AC2
170 : MUL 3,4,3   MUL * op
171 : ST 3,-4(1)   Storing Result
* TOFF = -5
* TOFF = -2
172 : LD 4,-2(1)   Loading left into AC2
173 : ADD 3,4,3   ADD + op
174 : ST 3,-2(1)   Storing Result
* TOFF = -3
175 : ST 3,-3(1)    Push Param
176 : LDA 1,0(1)    Ghost Frame become new active frame
177 : LDA 3,1(7)   Return addr in AC
* Func addr: 6
178 : JMP 7,-173(7)    Call output
179 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = 0
* CALL output
180 : ST 1,0(1) FP in ghost frame for output
* TOFF =-1
* Loading Parms
181 : LDA 1,0(1)    Ghost Frame become new active frame
182 : LDA 3,1(7)   Return addr in AC
* Func addr: 34
183 : JMP 7,-150(7)    Call outnl
184 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = 0
* End of Compound 
* TOFF = 0
* add Standard end in case of no return 
185 : LDC 2,0(0)   Set Ret val to 0
186 : LD 3,-1(1) Load Return addr
187 : LD 1,0(1)   Adjust Frame Pointer 
188 : JMP 7,0 (3)  Ret
* END OF FUNC main
*INIT 
0 : JMP 7,188(7)     Jmp to init 
189 : LDA 1,0(0)  set frist frame (end of globals) 
190 : ST 1,0(1)   Store old fp ()
* GLOBLS + STATICS (idk how to do this KEKW)
191 : LDA 3,1(7)  return addr in ac? 
* Main ADDR 39
192 : JMP 7,-154(7)   Jump to main
193 : HALT 0,0,0 DONE
