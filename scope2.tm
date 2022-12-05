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
* FUNCTION ant
39 : ST  3,-1(1)     Store Return addr
* TOFF = -3
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
40 : ST 1,-2(1)   Store fp in ghost Frame output? (IDK what that means tbh)
*LOADING CALL PARAMS
41 : LDA 1,-2(1)     Ghost frame becomes new active frame
 : LDA 3,1(7)     return addr in ac
 : JMP 7,-40(7)     Call func (IDK how to do this properly tbh
 : LDA 3,0(2)    Save Result in AC 
42 : ST 1,-2(1)   Store fp in ghost Frame output? (IDK what that means tbh)
*LOADING CALL PARAMS
43 : LDA 1,-2(1)     Ghost frame becomes new active frame
 : LDA 3,1(7)     return addr in ac
 : JMP 7,-40(7)     Call func (IDK how to do this properly tbh
 : LDA 3,0(2)    Save Result in AC 
44 : ST 1,-2(1)   Store fp in ghost Frame output? (IDK what that means tbh)
*LOADING CALL PARAMS
45 : LDA 1,-2(1)     Ghost frame becomes new active frame
 : LDA 3,1(7)     return addr in ac
 : JMP 7,-40(7)     Call func (IDK how to do this properly tbh
 : LDA 3,0(2)    Save Result in AC 
46 : ST 1,-2(1)   Store fp in ghost Frame output? (IDK what that means tbh)
*LOADING CALL PARAMS
47 : LDA 1,-2(1)     Ghost frame becomes new active frame
 : LDA 3,1(7)     return addr in ac
 : JMP 7,-40(7)     Call func (IDK how to do this properly tbh
 : LDA 3,0(2)    Save Result in AC 
48 : ST 1,-2(1)   Store fp in ghost Frame output? (IDK what that means tbh)
*LOADING CALL PARAMS
49 : LDA 1,-2(1)     Ghost frame becomes new active frame
 : LDA 3,1(7)     return addr in ac
 : JMP 7,-40(7)     Call func (IDK how to do this properly tbh
 : LDA 3,0(2)    Save Result in AC 
50 : ST 1,-2(1)   Store fp in ghost Frame output? (IDK what that means tbh)
51 : LDA 1,-2(1)     Ghost frame becomes new active frame
 : LDA 3,1(7)     return addr in ac
 : JMP 7,-40(7)     Call func (IDK how to do this properly tbh
 : LDA 3,0(2)    Save Result in AC 
52 : ST 1,-2(1)   Store fp in ghost Frame output? (IDK what that means tbh)
*LOADING CALL PARAMS
53 : LDA 1,-2(1)     Ghost frame becomes new active frame
 : LDA 3,1(7)     return addr in ac
 : JMP 7,-40(7)     Call func (IDK how to do this properly tbh
 : LDA 3,0(2)    Save Result in AC 
54 : ST 1,-2(1)   Store fp in ghost Frame output? (IDK what that means tbh)
*LOADING CALL PARAMS
55 : LDA 1,-2(1)     Ghost frame becomes new active frame
 : LDA 3,1(7)     return addr in ac
 : JMP 7,-40(7)     Call func (IDK how to do this properly tbh
 : LDA 3,0(2)    Save Result in AC 
56 : ST 1,-2(1)   Store fp in ghost Frame output? (IDK what that means tbh)
*LOADING CALL PARAMS
57 : LDA 1,-2(1)     Ghost frame becomes new active frame
 : LDA 3,1(7)     return addr in ac
 : JMP 7,-40(7)     Call func (IDK how to do this properly tbh
 : LDA 3,0(2)    Save Result in AC 
58 : ST 1,-2(1)   Store fp in ghost Frame output? (IDK what that means tbh)
*LOADING CALL PARAMS
59 : LDA 1,-2(1)     Ghost frame becomes new active frame
 : LDA 3,1(7)     return addr in ac
 : JMP 7,-40(7)     Call func (IDK how to do this properly tbh
 : LDA 3,0(2)    Save Result in AC 
60 : ST 1,-2(1)   Store fp in ghost Frame output? (IDK what that means tbh)
61 : LDA 1,-2(1)     Ghost frame becomes new active frame
 : LDA 3,1(7)     return addr in ac
 : JMP 7,-40(7)     Call func (IDK how to do this properly tbh
 : LDA 3,0(2)    Save Result in AC 
* CONST NODE
* CONST NODE
* CONST NODE
* CONST NODE
62 : ST 1,-2(1)   Store fp in ghost Frame output? (IDK what that means tbh)
*LOADING CALL PARAMS
63 : LDA 1,-2(1)     Ghost frame becomes new active frame
 : LDA 3,1(7)     return addr in ac
 : JMP 7,-40(7)     Call func (IDK how to do this properly tbh
 : LDA 3,0(2)    Save Result in AC 
64 : ST 1,-2(1)   Store fp in ghost Frame output? (IDK what that means tbh)
*LOADING CALL PARAMS
65 : LDA 1,-2(1)     Ghost frame becomes new active frame
 : LDA 3,1(7)     return addr in ac
 : JMP 7,-40(7)     Call func (IDK how to do this properly tbh
 : LDA 3,0(2)    Save Result in AC 
66 : ST 1,-2(1)   Store fp in ghost Frame output? (IDK what that means tbh)
*LOADING CALL PARAMS
67 : LDA 1,-2(1)     Ghost frame becomes new active frame
 : LDA 3,1(7)     return addr in ac
 : JMP 7,-40(7)     Call func (IDK how to do this properly tbh
 : LDA 3,0(2)    Save Result in AC 
68 : ST 1,-2(1)   Store fp in ghost Frame output? (IDK what that means tbh)
*LOADING CALL PARAMS
69 : LDA 1,-2(1)     Ghost frame becomes new active frame
 : LDA 3,1(7)     return addr in ac
 : JMP 7,-40(7)     Call func (IDK how to do this properly tbh
 : LDA 3,0(2)    Save Result in AC 
70 : ST 1,-2(1)   Store fp in ghost Frame output? (IDK what that means tbh)
71 : LDA 1,-2(1)     Ghost frame becomes new active frame
 : LDA 3,1(7)     return addr in ac
 : JMP 7,-40(7)     Call func (IDK how to do this properly tbh
 : LDA 3,0(2)    Save Result in AC 
* ** ** ** ** ** ** ** ** ** ** ** ** 
* FUNCTION main
72 : ST  3,-1(1)     Store Return addr
* TOFF = -5
* CONST NODE
* CONST NODE
73 : ST 1,-2(1)   Store fp in ghost Frame output? (IDK what that means tbh)
*LOADING CALL PARAMS
74 : LDA 1,-2(1)     Ghost frame becomes new active frame
 : LDA 3,1(7)     return addr in ac
 : JMP 7,-40(7)     Call func (IDK how to do this properly tbh
 : LDA 3,0(2)    Save Result in AC 
75 : ST 1,-2(1)   Store fp in ghost Frame output? (IDK what that means tbh)
*LOADING CALL PARAMS
* CONST
76 : LDC 3,2(0)   Load Integer Constant 
77 : ST 3,-5(1)   
78 : LDA 1,-2(1)     Ghost frame becomes new active frame
 : LDA 3,1(7)     return addr in ac
 : JMP 7,-40(7)     Call func (IDK how to do this properly tbh
 : LDA 3,0(2)    Save Result in AC 
* CONST NODE
79 : ST 1,-2(1)   Store fp in ghost Frame output? (IDK what that means tbh)
*LOADING CALL PARAMS
80 : LDA 1,-2(1)     Ghost frame becomes new active frame
 : LDA 3,1(7)     return addr in ac
 : JMP 7,-40(7)     Call func (IDK how to do this properly tbh
 : LDA 3,0(2)    Save Result in AC 
81 : ST 1,-2(1)   Store fp in ghost Frame output? (IDK what that means tbh)
*LOADING CALL PARAMS
82 : LDA 1,-2(1)     Ghost frame becomes new active frame
 : LDA 3,1(7)     return addr in ac
 : JMP 7,-40(7)     Call func (IDK how to do this properly tbh
 : LDA 3,0(2)    Save Result in AC 
83 : ST 1,-2(1)   Store fp in ghost Frame output? (IDK what that means tbh)
84 : LDA 1,-2(1)     Ghost frame becomes new active frame
 : LDA 3,1(7)     return addr in ac
 : JMP 7,-40(7)     Call func (IDK how to do this properly tbh
 : LDA 3,0(2)    Save Result in AC 
