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
* FUNCTION wallace
39 : ST  3,-1(1)     Store Return addr
* TOFF = -4
* COMPOUND STATEMENT 
*TOFF = -7
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* COMPOUND STATEMENT 
*TOFF = -11
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* COMPOUND STATEMENT 
*TOFF = -7
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
40 : ST 1,-2(1)   Store fp in ghost Frame output? (IDK what that means tbh)
*LOADING CALL PARAMS
*LOADING CALL PARAMS
41 : LDA 1,-2(1)     Ghost frame becomes new active frame
42 : LDA 3,1(7)     return addr in ac
43 : JMP 7,-40(7)     Call func (IDK how to do this properly tbh
44 : LDA 3,0(2)    Save Result in AC 
* COMPOUND STATEMENT 
*TOFF = -10
* ** ** ** ** ** ** ** ** ** ** ** ** 
* FUNCTION penguin
45 : ST  3,-1(1)     Store Return addr
* TOFF = -17
* COMPOUND STATEMENT 
*TOFF = -27
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* ** ** ** ** ** ** ** ** ** ** ** ** 
* FUNCTION Wendolene
46 : ST  3,-1(1)     Store Return addr
* TOFF = -33
* COMPOUND STATEMENT 
*TOFF = -7
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* ** ** ** ** ** ** ** ** ** ** ** ** 
* FUNCTION ramsBottom
47 : ST  3,-1(1)     Store Return addr
* TOFF = -9
* COMPOUND STATEMENT 
*TOFF = -16
* CONST NODE
48 : ST 1,-2(1)   Store fp in ghost Frame output? (IDK what that means tbh)
*LOADING CALL PARAMS
*LOADING CALL PARAMS
*LOADING CALL PARAMS
*LOADING CALL PARAMS
49 : LDA 1,-2(1)     Ghost frame becomes new active frame
50 : LDA 3,1(7)     return addr in ac
51 : JMP 7,-40(7)     Call func (IDK how to do this properly tbh
52 : LDA 3,0(2)    Save Result in AC 
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* ** ** ** ** ** ** ** ** ** ** ** ** 
* FUNCTION cheese
53 : ST  3,-1(1)     Store Return addr
* TOFF = -20
* COMPOUND STATEMENT 
*TOFF = -4
* CONST NODE
* CONST NODE
* ** ** ** ** ** ** ** ** ** ** ** ** 
* FUNCTION Wensleydale
54 : ST  3,-1(1)     Store Return addr
* TOFF = -8
* COMPOUND STATEMENT 
*TOFF = -4
55 : ST 1,-2(1)   Store fp in ghost Frame output? (IDK what that means tbh)
*LOADING CALL PARAMS
*LOADING CALL PARAMS
56 : LDA 1,-2(1)     Ghost frame becomes new active frame
57 : LDA 3,1(7)     return addr in ac
58 : JMP 7,-40(7)     Call func (IDK how to do this properly tbh
59 : LDA 3,0(2)    Save Result in AC 
* ** ** ** ** ** ** ** ** ** ** ** ** 
* FUNCTION LadyCampanula
60 : ST  3,-1(1)     Store Return addr
* TOFF = -8
* COMPOUND STATEMENT 
*TOFF = -4
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* ** ** ** ** ** ** ** ** ** ** ** ** 
* FUNCTION MrsTweedy
61 : ST  3,-1(1)     Store Return addr
* TOFF = -8
* COMPOUND STATEMENT 
*TOFF = -4
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* ** ** ** ** ** ** ** ** ** ** ** ** 
* FUNCTION TheWereRabbit
62 : ST  3,-1(1)     Store Return addr
* TOFF = -7
* COMPOUND STATEMENT 
*TOFF = -3
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* ** ** ** ** ** ** ** ** ** ** ** ** 
* FUNCTION main
63 : ST  3,-1(1)     Store Return addr
* TOFF = -5
* COMPOUND STATEMENT 
*TOFF = -154
64 : ST 1,-2(1)   Store fp in ghost Frame output? (IDK what that means tbh)
*LOADING CALL PARAMS
*LOADING CALL PARAMS
65 : LDA 1,-2(1)     Ghost frame becomes new active frame
66 : LDA 3,1(7)     return addr in ac
67 : JMP 7,-40(7)     Call func (IDK how to do this properly tbh
68 : LDA 3,0(2)    Save Result in AC 
69 : ST 1,-2(1)   Store fp in ghost Frame output? (IDK what that means tbh)
*LOADING CALL PARAMS
* CONST
70 : LDC 3,62(0)   Load Integer Constant 
71 : ST 3,-154(1)   
*LOADING CALL PARAMS
72 : LDA 1,-2(1)     Ghost frame becomes new active frame
73 : LDA 3,1(7)     return addr in ac
74 : JMP 7,-40(7)     Call func (IDK how to do this properly tbh
75 : LDA 3,0(2)    Save Result in AC 
* CONST NODE
* CONST NODE
* CONST NODE
76 : ST 1,-2(1)   Store fp in ghost Frame output? (IDK what that means tbh)
*LOADING CALL PARAMS
* CONST
77 : LDC 3,90(0)   Load Char Constant 
78 : ST 3,-154(1)   
*LOADING CALL PARAMS
79 : LDA 1,-2(1)     Ghost frame becomes new active frame
80 : LDA 3,1(7)     return addr in ac
81 : JMP 7,-40(7)     Call func (IDK how to do this properly tbh
82 : LDA 3,0(2)    Save Result in AC 
* CONST NODE
* CONST NODE
83 : ST 1,-2(1)   Store fp in ghost Frame output? (IDK what that means tbh)
*LOADING CALL PARAMS
*LOADING CALL PARAMS
*LOADING CALL PARAMS
*LOADING CALL PARAMS
84 : LDA 1,-2(1)     Ghost frame becomes new active frame
85 : LDA 3,1(7)     return addr in ac
86 : JMP 7,-40(7)     Call func (IDK how to do this properly tbh
87 : LDA 3,0(2)    Save Result in AC 
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
*INIT 
0 : JMP 7,75(7)     Jmp to init 
39 : LDA 1,0(0)  set frist frame
40 : ST 1,0(1)   Store old fp (point to self?)
* GLOBLS + STATICS (idk how to do this KEKW)
41 : LDA 3,1(7)  return addr in ac? 
42 : JMP 7,-41(7)   Jump to main
43 : HALT 0,0,0 DONE
