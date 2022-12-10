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
* CALL output
40 : ST 1,-2(1) FP in ghost frame for output
* TOFF =-3
* CONST
* TOFF =-4
41 : LDC 3,0(0)Load BOOL Const
42 : ST 3,-4(1)Push Param
* End CONST
43 : LDA 1,-2(1)    Ghost Frame become new active frame
44 : LDA 3,1(7)   Return addr in AC
45 : JMP 7,-29(7)    Call outputb
46 : LDA 3,0(2)  Save result in AC1
* End Call
* TOFF = -2
* End of Compound 
* TOFF = -2
* add Standard end in case of no return 
47 : LDC 2,0(0)   Set Ret val to 0
48 : LD 3,-1(1) Load Return addr
49 : LD 1,0(1)   Adjust Frame Pointer 
50 : JMP 7,0 (3)  Ret
* END OF FUNC main
*INIT 
0 : JMP 7,50(7)     Jmp to init 
51 : LDA 1,0(0)  set frist frame
52 : ST 1,0(1)   Store old fp (point to self?)
* GLOBLS + STATICS (idk how to do this KEKW)
53 : LDA 3,1(7)  return addr in ac? 
* Main ADDR 39
54 : JMP 7,-16(7)   Jump to main
55 : HALT 0,0,0 DONE
