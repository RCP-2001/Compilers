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
* FUNC DArtagnan
* TOFF = 0
39 : ST  3,-1(1) Store Ret Addr
* COMPOUND
* TOFF = 0
* End of Compound 
* TOFF = 0
* add Standard end in case of no return 
40 : LDC 2,0(0)   Set Ret val to 0
41 : LD 3,-1(1) Load Return addr
42 : LD 1,0(1)   Adjust Frame Pointer 
43 : JMP 7,0 (3)  Ret
* END OF FUNC DArtagnan
* ** ** ** ** ** ** ** ** ** ** ** ** 
* FUNC Athos
* TOFF = 0
44 : ST  3,-1(1) Store Ret Addr
* COMPOUND
* TOFF = 0
* CALL output
45 : ST 1,0(1) FP in ghost frame for output
* TOFF =-1
* Loading Parms
* CONST
* TOFF =-2
46 : LDC 3,666(0)Load Integer Const
47 : ST 3,-2(1)    Push Param
* End CONST
48 : LDA 1,0(1)    Ghost Frame become new active frame
49 : LDA 3,1(7)   Return addr in AC
* Func addr: 39
50 : JMP 7,-12(7)    Call DArtagnan
51 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = 0
* CALL output
52 : ST 1,0(1) FP in ghost frame for output
* TOFF =-1
* Loading Parms
* CONST
* TOFF =-2
53 : LDC 3,666(0)Load Integer Const
54 : ST 3,-2(1)    Push Param
* End CONST
* OP 
* CONST
55 : LDC 3,1(0)Load BOOL Const
* End CONST
* Loading Left Hand Side
56 : ST 3,-2(1)    Loading LHS (var true)
* TOFF = -3
* CONST
57 : LDC 3,6(0)Load Integer Const
* End CONST
* TOFF = -2
58 : LD 4,-2(1)   Loading left into AC2
59 : ADD 3,4,3   ADD + op
60 : ST 3,-2(1)   Storing Result
* TOFF = -3
61 : LDA 1,0(1)    Ghost Frame become new active frame
62 : LDA 3,1(7)   Return addr in AC
* Func addr: 39
63 : JMP 7,-25(7)    Call DArtagnan
64 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = 0
* CALL output
65 : ST 1,0(1) FP in ghost frame for output
* TOFF =-1
* Loading Parms
* ID
* (ID) TOFF =-2
* Local or Parm Var
66 : LD 3,0(1)    Load Variable a
67 : ST 3,-2(1)    Push Param
* End ID
* ID
* (ID) TOFF =-3
* Local or Parm Var
68 : LD 3,0(1)    Load Variable b
69 : ST 3,-3(1)    Push Param
* End ID
* ID
* (ID) TOFF =-4
* Local or Parm Var
70 : LD 3,0(1)    Load Variable c
71 : ST 3,-4(1)    Push Param
* End ID
72 : LDA 1,0(1)    Ghost Frame become new active frame
73 : LDA 3,1(7)   Return addr in AC
* Func addr: 44
74 : JMP 7,-31(7)    Call Athos
75 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = 0
* End of Compound 
* TOFF = 0
* add Standard end in case of no return 
76 : LDC 2,0(0)   Set Ret val to 0
77 : LD 3,-1(1) Load Return addr
78 : LD 1,0(1)   Adjust Frame Pointer 
79 : JMP 7,0 (3)  Ret
* END OF FUNC Athos
* ** ** ** ** ** ** ** ** ** ** ** ** 
* FUNC Aramis
* TOFF = 0
80 : ST  3,-1(1) Store Ret Addr
* COMPOUND
* TOFF = 0
* CALL output
81 : ST 1,0(1) FP in ghost frame for output
* TOFF =-1
* Loading Parms
* OP 
* ID
* Local or Parm Var
82 : LD 3,0(1)    Load Variable aa
* End ID
* Loading Left Hand Side
83 : ST 3,-1(1)    Loading LHS (var aa)
* TOFF = -2
* CONST
84 : LDC 3,1(0)Load Integer Const
* End CONST
* TOFF = -1
85 : LD 4,-1(1)   Loading left (?] into AC2
* Loacl Array
86 : LDA 6,0(1)     Load address of base
87 : SUB 6,6,3       Compute offset value
88 : LD 3,0(6)   Storing Array Value in AC1
* TOFF = -2
* ID
* (ID) TOFF =-3
* Local or Parm Var
89 : LD 3,0(1)    Load Variable ab
90 : ST 3,-3(1)    Push Param
* End ID
91 : LDA 1,0(1)    Ghost Frame become new active frame
92 : LDA 3,1(7)   Return addr in AC
* Func addr: 44
93 : JMP 7,-50(7)    Call Athos
94 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = 0
* CALL output
95 : ST 1,0(1) FP in ghost frame for output
* TOFF =-1
* Loading Parms
* OP 
* ID
* Local or Parm Var
96 : LD 3,0(1)    Load Variable aa
* End ID
* Loading Left Hand Side
97 : ST 3,-1(1)    Loading LHS (var aa)
* TOFF = -2
* CONST
98 : LDC 3,1(0)Load Integer Const
* End CONST
* TOFF = -1
99 : LD 4,-1(1)   Loading left (?] into AC2
* Loacl Array
100 : LDA 6,0(1)     Load address of base
101 : SUB 6,6,3       Compute offset value
102 : LD 3,0(6)   Storing Array Value in AC1
* TOFF = -2
* OP 
* ID
* Local or Parm Var
103 : LD 3,0(1)    Load Variable ab
* End ID
* Loading Left Hand Side
104 : ST 3,-2(1)    Loading LHS (var ab)
* TOFF = -3
* CONST
105 : LDC 3,2(0)Load Integer Const
* End CONST
* TOFF = -2
106 : LD 4,-2(1)   Loading left (?] into AC2
* Loacl Array
107 : LDA 6,0(1)     Load address of base
108 : SUB 6,6,3       Compute offset value
109 : LD 3,0(6)   Storing Array Value in AC1
* TOFF = -3
* OP 
* ID
* Local or Parm Var
110 : LD 3,0(1)    Load Variable ac
* End ID
* Loading Left Hand Side
111 : ST 3,-3(1)    Loading LHS (var ac)
* TOFF = -4
* CONST
112 : LDC 3,3(0)Load Integer Const
* End CONST
* TOFF = -3
113 : LD 4,-3(1)   Loading left (?] into AC2
* Loacl Array
114 : LDA 6,0(1)     Load address of base
115 : SUB 6,6,3       Compute offset value
116 : LD 3,0(6)   Storing Array Value in AC1
* TOFF = -4
117 : LDA 1,0(1)    Ghost Frame become new active frame
118 : LDA 3,1(7)   Return addr in AC
* Func addr: 44
119 : JMP 7,-76(7)    Call Athos
120 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = 0
* CALL output
121 : ST 1,0(1) FP in ghost frame for output
* TOFF =-1
* Loading Parms
* OP 
* ID
* Local or Parm Var
122 : LD 3,0(1)    Load Variable aa
* End ID
* Loading Left Hand Side
123 : ST 3,-1(1)    Loading LHS (var aa)
* TOFF = -2
* CONST
124 : LDC 3,1(0)Load Integer Const
* End CONST
* TOFF = -1
125 : LD 4,-1(1)   Loading left (?] into AC2
* Loacl Array
126 : LDA 6,0(1)     Load address of base
127 : SUB 6,6,3       Compute offset value
128 : LD 3,0(6)   Storing Array Value in AC1
* TOFF = -2
* OP 
* ID
* Local or Parm Var
129 : LD 3,0(1)    Load Variable ab
* End ID
* Loading Left Hand Side
130 : ST 3,-2(1)    Loading LHS (var ab)
* TOFF = -3
* CONST
131 : LDC 3,2(0)Load Integer Const
* End CONST
* TOFF = -2
132 : LD 4,-2(1)   Loading left (?] into AC2
* Loacl Array
133 : LDA 6,0(1)     Load address of base
134 : SUB 6,6,3       Compute offset value
135 : LD 3,0(6)   Storing Array Value in AC1
* TOFF = -3
* OP 
* ID
* Local or Parm Var
136 : LD 3,0(1)    Load Variable ac
* End ID
* Loading Left Hand Side
137 : ST 3,-3(1)    Loading LHS (var ac)
* TOFF = -4
* CONST
138 : LDC 3,3(0)Load Integer Const
* End CONST
* TOFF = -3
139 : LD 4,-3(1)   Loading left (?] into AC2
* Loacl Array
140 : LDA 6,0(1)     Load address of base
141 : SUB 6,6,3       Compute offset value
142 : LD 3,0(6)   Storing Array Value in AC1
* TOFF = -4
* OP 
* CONST
143 : LDC 3,5(0)Load Integer Const
* End CONST
* Loading Left Hand Side
144 : ST 3,-4(1)    Loading LHS (var 5)
* TOFF = -5
* CONST
145 : LDC 3,6(0)Load Integer Const
* End CONST
* TOFF = -4
146 : LD 4,-4(1)   Loading left into AC2
147 : AND 3,4,3   AND op
148 : ST 3,-4(1)   Storing Result
* TOFF = -5
149 : LDA 1,0(1)    Ghost Frame become new active frame
150 : LDA 3,1(7)   Return addr in AC
* Func addr: 44
151 : JMP 7,-108(7)    Call Athos
152 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = 0
* End of Compound 
* TOFF = 0
* add Standard end in case of no return 
153 : LDC 2,0(0)   Set Ret val to 0
154 : LD 3,-1(1) Load Return addr
155 : LD 1,0(1)   Adjust Frame Pointer 
156 : JMP 7,0 (3)  Ret
* END OF FUNC Aramis
* ** ** ** ** ** ** ** ** ** ** ** ** 
* FUNC Porthos
* TOFF = 0
157 : ST  3,-1(1) Store Ret Addr
* COMPOUND
* TOFF = 0
158 : LDC 3,1(0)    LOAD SIZE of ARRAY
159 : ST 3,1(1) Save Array Size
160 : LDC 3,2(0)    LOAD SIZE of ARRAY
161 : ST 3,1(1) Save Array Size
162 : LDC 3,3(0)    LOAD SIZE of ARRAY
163 : ST 3,1(1) Save Array Size
* CALL output
164 : ST 1,0(1) FP in ghost frame for output
* TOFF =-1
* Loading Parms
* CALL output
165 : ST 1,-1(1) FP in ghost frame for output
* TOFF =-2
* Loading Parms
* CONST
* TOFF =-3
166 : LDC 3,1(0)Load Integer Const
167 : ST 3,-3(1)    Push Param
* End CONST
* CONST
* TOFF =-4
168 : LDC 3,1(0)Load BOOL Const
169 : ST 3,-4(1)    Push Param
* End CONST
* CONST
* TOFF =-5
170 : LDC 3,'x'(0)Load Char Const
171 : ST 3,-5(1)    Push Param
* End CONST
172 : LDA 1,-1(1)    Ghost Frame become new active frame
173 : LDA 3,1(7)   Return addr in AC
* Func addr: 44
174 : JMP 7,-131(7)    Call Athos
175 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -1
* CALL output
176 : ST 1,-1(1) FP in ghost frame for output
* TOFF =-2
* Loading Parms
* CONST
* TOFF =-3
177 : LDC 3,1(0)Load BOOL Const
178 : ST 3,-3(1)    Push Param
* End CONST
* CONST
* TOFF =-4
179 : LDC 3,'w'(0)Load Char Const
180 : ST 3,-4(1)    Push Param
* End CONST
* CONST
* TOFF =-5
181 : LDC 3,78(0)Load Integer Const
182 : ST 3,-5(1)    Push Param
* End CONST
183 : LDA 1,-1(1)    Ghost Frame become new active frame
184 : LDA 3,1(7)   Return addr in AC
* Func addr: 157
185 : JMP 7,-29(7)    Call Porthos
186 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -1
* CALL output
187 : ST 1,-1(1) FP in ghost frame for output
* TOFF =-2
* Loading Parms
* ID
* (ID) TOFF =-3
* Local or Parm Var
188 : LD 3,0(1)    Load Variable a
189 : ST 3,-3(1)    Push Param
* End ID
* ID
* (ID) TOFF =-4
* Local or Parm Var
190 : LD 3,0(1)    Load Variable b
191 : ST 3,-4(1)    Push Param
* End ID
* ID
* (ID) TOFF =-5
* Local or Parm Var
192 : LD 3,0(1)    Load Variable c
193 : ST 3,-5(1)    Push Param
* End ID
194 : LDA 1,-1(1)    Ghost Frame become new active frame
195 : LDA 3,1(7)   Return addr in AC
* Func addr: 80
196 : JMP 7,-117(7)    Call Aramis
197 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -1
198 : LDA 1,0(1)    Ghost Frame become new active frame
199 : LDA 3,1(7)   Return addr in AC
* Func addr: 44
200 : JMP 7,-157(7)    Call Athos
201 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = 0
* CALL output
202 : ST 1,0(1) FP in ghost frame for output
* TOFF =-1
* Loading Parms
* OP 
* CALL output
203 : ST 1,-1(1) FP in ghost frame for output
* TOFF =-2
* Loading Parms
* CONST
* TOFF =-3
204 : LDC 3,1(0)Load Integer Const
205 : ST 3,-3(1)    Push Param
* End CONST
* CONST
* TOFF =-4
206 : LDC 3,1(0)Load BOOL Const
207 : ST 3,-4(1)    Push Param
* End CONST
* CONST
* TOFF =-5
208 : LDC 3,'x'(0)Load Char Const
209 : ST 3,-5(1)    Push Param
* End CONST
210 : LDA 1,-1(1)    Ghost Frame become new active frame
211 : LDA 3,1(7)   Return addr in AC
* Func addr: 44
212 : JMP 7,-169(7)    Call Athos
213 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -1
* Loading Left Hand Side
214 : ST 3,-1(1)    Loading LHS (var Athos)
* TOFF = -2
* CONST
215 : LDC 3,6(0)Load Integer Const
* End CONST
* TOFF = -1
216 : LD 4,-1(1)   Loading left into AC2
217 : MUL 3,4,3   MUL * op
218 : ST 3,-1(1)   Storing Result
* TOFF = -2
* OP 
* CALL output
219 : ST 1,-2(1) FP in ghost frame for output
* TOFF =-3
* Loading Parms
* CONST
* TOFF =-4
220 : LDC 3,1(0)Load BOOL Const
221 : ST 3,-4(1)    Push Param
* End CONST
* CONST
* TOFF =-5
222 : LDC 3,'w'(0)Load Char Const
223 : ST 3,-5(1)    Push Param
* End CONST
* CONST
* TOFF =-6
224 : LDC 3,78(0)Load Integer Const
225 : ST 3,-6(1)    Push Param
* End CONST
226 : LDA 1,-2(1)    Ghost Frame become new active frame
227 : LDA 3,1(7)   Return addr in AC
* Func addr: 157
228 : JMP 7,-72(7)    Call Porthos
229 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -2
* Loading Left Hand Side
230 : ST 3,-2(1)    Loading LHS (var Porthos)
* TOFF = -3
* CONST
231 : LDC 3,1(0)Load BOOL Const
* End CONST
* TOFF = -2
232 : LD 4,-2(1)   Loading left into AC2
233 : AND 3,4,3   AND op
234 : ST 3,-2(1)   Storing Result
* TOFF = -3
* CALL output
235 : ST 1,-3(1) FP in ghost frame for output
* TOFF =-4
* Loading Parms
* ID
* (ID) TOFF =-5
* Local or Parm Var
236 : LD 3,0(1)    Load Variable a
237 : ST 3,-5(1)    Push Param
* End ID
* ID
* (ID) TOFF =-6
* Local or Parm Var
238 : LD 3,0(1)    Load Variable b
239 : ST 3,-6(1)    Push Param
* End ID
* ID
* (ID) TOFF =-7
* Local or Parm Var
240 : LD 3,0(1)    Load Variable c
241 : ST 3,-7(1)    Push Param
* End ID
242 : LDA 1,-3(1)    Ghost Frame become new active frame
243 : LDA 3,1(7)   Return addr in AC
* Func addr: 80
244 : JMP 7,-165(7)    Call Aramis
245 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -3
246 : LDA 1,0(1)    Ghost Frame become new active frame
247 : LDA 3,1(7)   Return addr in AC
* Func addr: 44
248 : JMP 7,-205(7)    Call Athos
249 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = 0
* CALL output
250 : ST 1,0(1) FP in ghost frame for output
* TOFF =-1
* Loading Parms
* CALL output
251 : ST 1,-1(1) FP in ghost frame for output
* TOFF =-2
* Loading Parms
* CONST
* TOFF =-3
252 : LDC 3,1(0)Load Integer Const
253 : ST 3,-3(1)    Push Param
* End CONST
* CONST
* TOFF =-4
254 : LDC 3,1(0)Load BOOL Const
255 : ST 3,-4(1)    Push Param
* End CONST
* CONST
* TOFF =-5
256 : LDC 3,'x'(0)Load Char Const
257 : ST 3,-5(1)    Push Param
* End CONST
258 : LDA 1,-1(1)    Ghost Frame become new active frame
259 : LDA 3,1(7)   Return addr in AC
* Func addr: 44
260 : JMP 7,-217(7)    Call Athos
261 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -1
* CALL output
262 : ST 1,-1(1) FP in ghost frame for output
* TOFF =-2
* Loading Parms
* CONST
* TOFF =-3
263 : LDC 3,1(0)Load BOOL Const
264 : ST 3,-3(1)    Push Param
* End CONST
* CONST
* TOFF =-4
265 : LDC 3,'w'(0)Load Char Const
266 : ST 3,-4(1)    Push Param
* End CONST
* CONST
* TOFF =-5
267 : LDC 3,78(0)Load Integer Const
268 : ST 3,-5(1)    Push Param
* End CONST
269 : LDA 1,-1(1)    Ghost Frame become new active frame
270 : LDA 3,1(7)   Return addr in AC
* Func addr: 157
271 : JMP 7,-115(7)    Call Porthos
272 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -1
273 : LDA 1,0(1)    Ghost Frame become new active frame
274 : LDA 3,1(7)   Return addr in AC
* Func addr: 44
275 : JMP 7,-232(7)    Call Athos
276 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = 0
* CALL output
277 : ST 1,0(1) FP in ghost frame for output
* TOFF =-1
* Loading Parms
* CALL output
278 : ST 1,-1(1) FP in ghost frame for output
* TOFF =-2
* Loading Parms
* CONST
* TOFF =-3
279 : LDC 3,1(0)Load Integer Const
280 : ST 3,-3(1)    Push Param
* End CONST
* CONST
* TOFF =-4
281 : LDC 3,1(0)Load BOOL Const
282 : ST 3,-4(1)    Push Param
* End CONST
* CONST
* TOFF =-5
283 : LDC 3,'x'(0)Load Char Const
284 : ST 3,-5(1)    Push Param
* End CONST
285 : LDA 1,-1(1)    Ghost Frame become new active frame
286 : LDA 3,1(7)   Return addr in AC
* Func addr: 44
287 : JMP 7,-244(7)    Call Athos
288 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -1
* CALL output
289 : ST 1,-1(1) FP in ghost frame for output
* TOFF =-2
* Loading Parms
* CONST
* TOFF =-3
290 : LDC 3,1(0)Load BOOL Const
291 : ST 3,-3(1)    Push Param
* End CONST
* CONST
* TOFF =-4
292 : LDC 3,'w'(0)Load Char Const
293 : ST 3,-4(1)    Push Param
* End CONST
* CONST
* TOFF =-5
294 : LDC 3,78(0)Load Integer Const
295 : ST 3,-5(1)    Push Param
* End CONST
296 : LDA 1,-1(1)    Ghost Frame become new active frame
297 : LDA 3,1(7)   Return addr in AC
* Func addr: 157
298 : JMP 7,-142(7)    Call Porthos
299 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -1
* CALL output
300 : ST 1,-1(1) FP in ghost frame for output
* TOFF =-2
* Loading Parms
* ID
* (ID) TOFF =-3
* Local or Parm Var
301 : LD 3,0(1)    Load Variable a
302 : ST 3,-3(1)    Push Param
* End ID
* ID
* (ID) TOFF =-4
* Local or Parm Var
303 : LD 3,0(1)    Load Variable b
304 : ST 3,-4(1)    Push Param
* End ID
* ID
* (ID) TOFF =-5
* Local or Parm Var
305 : LD 3,0(1)    Load Variable c
306 : ST 3,-5(1)    Push Param
* End ID
307 : LDA 1,-1(1)    Ghost Frame become new active frame
308 : LDA 3,1(7)   Return addr in AC
* Func addr: 80
309 : JMP 7,-230(7)    Call Aramis
310 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -1
* CONST
* TOFF =-2
311 : LDC 3,1(0)Load BOOL Const
312 : ST 3,-2(1)    Push Param
* End CONST
* CONST
* TOFF =-3
313 : LDC 3,34(0)Load Integer Const
314 : ST 3,-3(1)    Push Param
* End CONST
* ID
* (ID) TOFF =-4
* Local or Parm Var
315 : LD 3,0(1)    Load Variable a
316 : ST 3,-4(1)    Push Param
* End ID
* CALL output
317 : ST 1,-4(1) FP in ghost frame for output
* TOFF =-5
* Loading Parms
318 : LDA 1,-4(1)    Ghost Frame become new active frame
319 : LDA 3,1(7)   Return addr in AC
* Func addr: 39
320 : JMP 7,-282(7)    Call DArtagnan
321 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -4
322 : LDA 1,0(1)    Ghost Frame become new active frame
323 : LDA 3,1(7)   Return addr in AC
* Func addr: 44
324 : JMP 7,-281(7)    Call Athos
325 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = 0
* CALL output
326 : ST 1,0(1) FP in ghost frame for output
* TOFF =-1
* Loading Parms
* CALL output
327 : ST 1,-1(1) FP in ghost frame for output
* TOFF =-2
* Loading Parms
328 : LDA 1,-1(1)    Ghost Frame become new active frame
329 : LDA 3,1(7)   Return addr in AC
* Func addr: 39
330 : JMP 7,-292(7)    Call DArtagnan
331 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -1
* ID
* (ID) TOFF =-2
* Local or Parm Var
332 : LD 3,0(1)    Load Variable thx1138
333 : ST 3,-2(1)    Push Param
* End ID
* TOFF =-3
* Assing Op
* Left hand side in AC1
* OP 
* ID
* Local or Parm Var
334 : LD 3,0(1)    Load Variable a
* End ID
* Loading Left Hand Side
335 : ST 3,-3(1)    Loading LHS (var a)
* TOFF = -4
* CONST
336 : LDC 3,0(0)Load Integer Const
* End CONST
* TOFF = -3
337 : LD 4,-3(1)   Loading left (?] into AC2
* Loacl Array
338 : LDA 6,0(1)     Load address of base
339 : SUB 6,6,3       Compute offset value
340 : LD 3,0(6)   Storing Array Value in AC1
* TOFF = -4
* Storing Left Hand Side
341 : ST 3,-4(1)    Loading LHS (var [)
* TOFF = -5
* Loading Right Hand Side
* OP 
* ID
* Local or Parm Var
342 : LD 3,0(1)    Load Variable a
* End ID
* Loading Left Hand Side
343 : ST 3,-5(1)    Loading LHS (var a)
* TOFF = -6
* CONST
344 : LDC 3,0(0)Load Integer Const
* End CONST
* TOFF = -5
345 : LD 4,-5(1)   Loading left (?] into AC2
* Loacl Array
346 : LDA 6,0(1)     Load address of base
347 : SUB 6,6,3       Compute offset value
348 : LD 3,0(6)   Storing Array Value in AC1
* TOFF = -6
* TOFF = -5
* Assinging to array Location
349 : ST 3,0(6) Store AC1 in array
* TOFF = -3
350 : ST 3,-3(1)    Push Param
* End Assing Op
351 : LDA 1,0(1)    Ghost Frame become new active frame
352 : LDA 3,1(7)   Return addr in AC
* Func addr: 44
353 : JMP 7,-310(7)    Call Athos
354 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = 0
* RETURN
355 : LD 3,-1(1)    Load return addr
356 : LD 1,0(1)   Frame Pointer Adjusted
357 : JMP 7,0(3) Return
* End of Compound 
* TOFF = 0
* add Standard end in case of no return 
358 : LDC 2,0(0)   Set Ret val to 0
359 : LD 3,-1(1) Load Return addr
360 : LD 1,0(1)   Adjust Frame Pointer 
361 : JMP 7,0 (3)  Ret
* END OF FUNC Porthos
*INIT 
0 : JMP 7,361(7)     Jmp to init 
362 : LDA 1,0(0)  set frist frame (end of globals) 
363 : ST 1,0(1)   Store old fp ()
* GLOBLS + STATICS (idk how to do this KEKW)
364 : LDA 3,1(7)  return addr in ac? 
* Main ADDR 0
365 : JMP 7,-366(7)   Jump to main
366 : HALT 0,0,0 DONE
