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
* FUNCTION main
39 : ST  3,-1(1)     Store Return addr
* TOFF = -2
40 : ST 1,-2(1)   Store fp in ghost Frame output? (IDK what that means tbh)
*LOADING CALL PARAMS
* CONST
41 : LDC 3,666(0)   Load Integer Constant 
42 : ST 3,-2(1)   
43 : LDA 1,-2(1)     Ghost frame becomes new active frame
44 : LDA 3,1(7)     return addr in ac
45 : JMP 7,-40(7)     Call func (IDK how to do this properly tbh
46 : LDA 3,0(2)    Save Result in AC 
* CONST NODE
47 : ST 1,-2(1)   Store fp in ghost Frame output? (IDK what that means tbh)
*LOADING CALL PARAMS
* CONST
48 : LDC 3,1(0)   Load Integer Constant 
49 : ST 3,-2(1)   
50 : LDA 1,-2(1)     Ghost frame becomes new active frame
51 : LDA 3,1(7)     return addr in ac
52 : JMP 7,-40(7)     Call func (IDK how to do this properly tbh
53 : LDA 3,0(2)    Save Result in AC 
* CONST NODE
54 : ST 1,-2(1)   Store fp in ghost Frame output? (IDK what that means tbh)
55 : LDA 1,-2(1)     Ghost frame becomes new active frame
56 : LDA 3,1(7)     return addr in ac
57 : JMP 7,-40(7)     Call func (IDK how to do this properly tbh
58 : LDA 3,0(2)    Save Result in AC 
59 : ST 1,-2(1)   Store fp in ghost Frame output? (IDK what that means tbh)
60 : LDA 1,-2(1)     Ghost frame becomes new active frame
61 : LDA 3,1(7)     return addr in ac
62 : JMP 7,-40(7)     Call func (IDK how to do this properly tbh
63 : LDA 3,0(2)    Save Result in AC 
64 : ST 1,-2(1)   Store fp in ghost Frame output? (IDK what that means tbh)
65 : LDA 1,-2(1)     Ghost frame becomes new active frame
66 : LDA 3,1(7)     return addr in ac
67 : JMP 7,-40(7)     Call func (IDK how to do this properly tbh
68 : LDA 3,0(2)    Save Result in AC 
