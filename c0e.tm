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
* TOFF = -3
* Assing Op
* ID
* Local or Parm Var
40 : LD 3,-2(1)    Load Variable x
* End ID
* Loading Left Hand Side
41 : ST 3,-3(1)    Loading LHS (var x)
* TOFF = -4
* Loading Right Hand Side
* CONST
42 : LDC 3,1023(0)Load Integer Const
* End CONST
* TOFF = -3
* Variablex LOC is -2
* Local or Parmaets Var
43 : ST 3,-2(1)    Loading LHS (var x)
* CALL output
44 : ST 1,-3(1) FP in ghost frame for output
* TOFF =-4
* Loading Parms
* TOFF =-5
* Assing Op
* ID
* Local or Parm Var
45 : LD 3,-2(1)    Load Variable x
* End ID
* Loading Left Hand Side
46 : ST 3,-5(1)    Loading LHS (var x)
* TOFF = -6
* Loading Right Hand Side
* TOFF = -5
* INC OPERATOR
47 : LD 4,-5(1)   Loading left into AC2
48 : LDC 3,1(0)   Loading 1 into AC1
49 : ADD 3,4,3   ADD ++ op
* Variablex LOC is -2
* Local or Parmaets Var
50 : ST 3,-2(1)    Loading LHS (var x)
51 : ST 3,-5(1)    Push Param
52 : LDA 1,-3(1)    Ghost Frame become new active frame
53 : LDA 3,1(7)   Return addr in AC
* Func addr: 6
54 : JMP 7,-49(7)    Call output
55 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -3
* CALL output
56 : ST 1,-3(1) FP in ghost frame for output
* TOFF =-4
* Loading Parms
57 : LDA 1,-3(1)    Ghost Frame become new active frame
58 : LDA 3,1(7)   Return addr in AC
* Func addr: 34
59 : JMP 7,-26(7)    Call outnl
60 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -3
* CALL output
61 : ST 1,-3(1) FP in ghost frame for output
* TOFF =-4
* Loading Parms
* ID
* TOFF =-5
* Local or Parm Var
62 : LD 3,-2(1)    Load Variable x
63 : ST 3,-5(1)    Push Param
* End ID
64 : LDA 1,-3(1)    Ghost Frame become new active frame
65 : LDA 3,1(7)   Return addr in AC
* Func addr: 6
66 : JMP 7,-61(7)    Call output
67 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -3
* CALL output
68 : ST 1,-3(1) FP in ghost frame for output
* TOFF =-4
* Loading Parms
69 : LDA 1,-3(1)    Ghost Frame become new active frame
70 : LDA 3,1(7)   Return addr in AC
* Func addr: 34
71 : JMP 7,-38(7)    Call outnl
72 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -3
* CALL output
73 : ST 1,-3(1) FP in ghost frame for output
* TOFF =-4
* Loading Parms
* TOFF =-5
* Assing Op
* ID
* Local or Parm Var
74 : LD 3,-2(1)    Load Variable x
* End ID
* Loading Left Hand Side
75 : ST 3,-5(1)    Loading LHS (var x)
* TOFF = -6
* Loading Right Hand Side
* TOFF = -5
* DEC OPERATOR
76 : LD 4,-5(1)   Loading left (only?) into AC2
77 : LDC 3,1(0)   Loading 1 into AC1
78 : SUB 3,4,3   SUB -- op
* Variablex LOC is -2
* Local or Parmaets Var
79 : ST 3,-2(1)    Loading LHS (var x)
80 : ST 3,-5(1)    Push Param
81 : LDA 1,-3(1)    Ghost Frame become new active frame
82 : LDA 3,1(7)   Return addr in AC
* Func addr: 6
83 : JMP 7,-78(7)    Call output
84 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -3
* CALL output
85 : ST 1,-3(1) FP in ghost frame for output
* TOFF =-4
* Loading Parms
86 : LDA 1,-3(1)    Ghost Frame become new active frame
87 : LDA 3,1(7)   Return addr in AC
* Func addr: 34
88 : JMP 7,-55(7)    Call outnl
89 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -3
* CALL output
90 : ST 1,-3(1) FP in ghost frame for output
* TOFF =-4
* Loading Parms
* ID
* TOFF =-5
* Local or Parm Var
91 : LD 3,-2(1)    Load Variable x
92 : ST 3,-5(1)    Push Param
* End ID
93 : LDA 1,-3(1)    Ghost Frame become new active frame
94 : LDA 3,1(7)   Return addr in AC
* Func addr: 6
95 : JMP 7,-90(7)    Call output
96 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -3
* CALL output
97 : ST 1,-3(1) FP in ghost frame for output
* TOFF =-4
* Loading Parms
98 : LDA 1,-3(1)    Ghost Frame become new active frame
99 : LDA 3,1(7)   Return addr in AC
* Func addr: 34
100 : JMP 7,-67(7)    Call outnl
101 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -3
* End of Compound 
* TOFF = -2
* add Standard end in case of no return 
102 : LDC 2,0(0)   Set Ret val to 0
103 : LD 3,-1(1) Load Return addr
104 : LD 1,0(1)   Adjust Frame Pointer 
105 : JMP 7,0 (3)  Ret
* END OF FUNC main
*INIT 
0 : JMP 7,105(7)     Jmp to init 
106 : LDA 1,0(0)  set frist frame (end of globals) 
107 : ST 1,0(1)   Store old fp ()
* GLOBLS + STATICS (idk how to do this KEKW)
108 : LDA 3,1(7)  return addr in ac? 
* Main ADDR 39
109 : JMP 7,-71(7)   Jump to main
110 : HALT 0,0,0 DONE
