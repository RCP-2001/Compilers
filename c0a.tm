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
* TOFF = -2
* Assing Op
* ID
* Global or LocalStatic Var
40 : LD 3,0(0)    Load Variable x
* End ID
* Loading Left Hand Side
41 : ST 3,-2(1)    Loading LHS (var x)
* TOFF = -3
* Loading Right Hand Side
* CONST
42 : LDC 3,753(0)Load Integer Const
* End CONST
* TOFF = -2
* Variablex LOC is 0
* Global or LocalStatic Var
43 : ST 3,0(0)    Loading LHS (var x)
* Assing Op
* ID
* Global or LocalStatic Var
44 : LD 3,-1(0)    Load Variable y
* End ID
* Loading Left Hand Side
45 : ST 3,-2(1)    Loading LHS (var y)
* TOFF = -3
* Loading Right Hand Side
* CONST
46 : LDC 3,444(0)Load Integer Const
* End CONST
* TOFF = -2
* Variabley LOC is -1
* Global or LocalStatic Var
47 : ST 3,-1(0)    Loading LHS (var y)
* CALL output
48 : ST 1,-2(1) FP in ghost frame for output
* TOFF =-3
* Loading Parms
* TOFF =-4
* Assing Op
* ID
* Global or LocalStatic Var
49 : LD 3,0(0)    Load Variable x
* End ID
* Loading Left Hand Side
50 : ST 3,-4(1)    Loading LHS (var x)
* TOFF = -5
* Loading Right Hand Side
* ID
* Global or LocalStatic Var
51 : LD 3,-1(0)    Load Variable y
* End ID
* TOFF = -4
52 : LD 4,-4(1)   Loading left into AC2
53 : ADD 3,4,3   ADD += op
* Variablex LOC is 0
* Global or LocalStatic Var
54 : ST 3,0(0)    Loading LHS (var x)
55 : ST 3,-4(1)    Push Param
56 : LDA 1,-2(1)    Ghost Frame become new active frame
57 : LDA 3,1(7)   Return addr in AC
* Func addr: 6
58 : JMP 7,-53(7)    Call output
59 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -2
* CALL output
60 : ST 1,-2(1) FP in ghost frame for output
* TOFF =-3
* Loading Parms
* TOFF =-4
* Assing Op
* ID
* Global or LocalStatic Var
61 : LD 3,-1(0)    Load Variable y
* End ID
* Loading Left Hand Side
62 : ST 3,-4(1)    Loading LHS (var y)
* TOFF = -5
* Loading Right Hand Side
* ID
* Global or LocalStatic Var
63 : LD 3,0(0)    Load Variable x
* End ID
* TOFF = -4
64 : LD 4,-4(1)   Loading left into AC2
65 : SUB 3,4,3   ADD -= op
* Variabley LOC is -1
* Global or LocalStatic Var
66 : ST 3,-1(0)    Loading LHS (var y)
67 : ST 3,-4(1)    Push Param
68 : LDA 1,-2(1)    Ghost Frame become new active frame
69 : LDA 3,1(7)   Return addr in AC
* Func addr: 6
70 : JMP 7,-65(7)    Call output
71 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -2
* CALL output
72 : ST 1,-2(1) FP in ghost frame for output
* TOFF =-3
* Loading Parms
73 : LDA 1,-2(1)    Ghost Frame become new active frame
74 : LDA 3,1(7)   Return addr in AC
* Func addr: 34
75 : JMP 7,-42(7)    Call outnl
76 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -2
* End of Compound 
* TOFF = -2
* add Standard end in case of no return 
77 : LDC 2,0(0)   Set Ret val to 0
78 : LD 3,-1(1) Load Return addr
79 : LD 1,0(1)   Adjust Frame Pointer 
80 : JMP 7,0 (3)  Ret
* END OF FUNC main
*INIT 
0 : JMP 7,80(7)     Jmp to init 
81 : LDA 1,-2(0)  set frist frame (end of globals) 
82 : ST 1,0(1)   Store old fp ()
* GLOBLS + STATICS (idk how to do this KEKW)
83 : LDA 3,1(7)  return addr in ac? 
* Main ADDR 39
84 : JMP 7,-46(7)   Jump to main
85 : HALT 0,0,0 DONE
