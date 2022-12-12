#include "CodeGen.h"

extern treeNode *GLOBAL_HEAD;
extern int goffset;

static int currentAddr = 39;
static int TOFF = 0;
static int MainAddr = 0;
static int InputAddr = 1;
static int InputbAddr = 12;
static int InputcAddr = 23;
static int OutputAddr = 6;
static int OutputbAddr = 17;
static int OutputcAddr = 28;
static int OutnlAddr = 34;

static int GetAddr(std::string FuncName)
{
        if (FuncName == "input")
        {
                return InputAddr;
        }
        else if (FuncName == "inputb")
        {
                return InputbAddr;
        }
        else if (FuncName == "inputc")
        {
                return InputcAddr;
        }
        else if (FuncName == "output")
        {
                return OutputAddr;
        }
        else if (FuncName == "outputb")
        {
                return OutputbAddr;
        }
        else if (FuncName == "outputc")
        {
                return OutputcAddr;
        }
        else if (FuncName == "outnl")
        {
                return OutnlAddr;
        }
        // If its not main or a built in func, look for actual func
        treeNode *CurrentNode = GLOBAL_HEAD;
        while (CurrentNode != NULL)
        {
                if (CurrentNode->Kind() == DeclK && CurrentNode->DKind() == FuncK)
                {
                        if (FuncName == CurrentNode->token()->tokenstr)
                        {
                                return CurrentNode->address;
                        }
                }
                CurrentNode = CurrentNode->nextSibling();
        }
        // Return 0 if cant be found
        return 0;
}

void GenerateIOLib(std::ofstream &Fileout)
{
        Fileout << "* ** ** ** ** ** ** ** ** ** ** ** **" << std::endl;
        Fileout << "*FUNCTION input" << std::endl;
        Fileout << "1 : ST 3, -1(1)Store return address" << std::endl;
        Fileout << "2 : IN 2, 2, 2 Grab int input " << std::endl;
        Fileout << "3 : LD 3, -1(1)Load return address" << std::endl;
        Fileout << "4 : LD 1, 0(1)Adjust fp" << std::endl;
        Fileout << "5 : JMP 7, 0(3)Return" << std::endl;
        Fileout << "*END FUNCTION input" << std::endl;
        Fileout << "*";
        Fileout << "************************* " << std::endl;
        Fileout << "*FUNCTION output " << std::endl;
        Fileout << "6 : ST 3, -1(1)Store return address" << std::endl;
        Fileout << "7 : LD 3, -2(1)Load parameter " << std::endl;
        Fileout << "8 : OUT 3, 3, 3 Output integer " << std::endl;
        Fileout << "9 : LD 3, -1(1)Load return address" << std::endl;
        Fileout << "10 : LD 1, 0(1)Adjust fp" << std::endl;
        Fileout << "11 : JMP 7, 0(3)Return" << std::endl;
        Fileout << "*END FUNCTION output " << std::endl;
        Fileout << "* " << std::endl;
        Fileout << "************************* " << std::endl;
        Fileout << "*FUNCTION inputb " << std::endl;
        Fileout << "12 : ST 3, -1(1)Store return address" << std::endl;
        Fileout << "13 : INB 2, 2, 2 Grab bool input" << std::endl;
        Fileout << "14 : LD 3, -1(1)Load return address" << std::endl;
        Fileout << "15 : LD 1, 0(1)Adjust fp" << std::endl;
        Fileout << "16 : JMP 7, 0(3)Return" << std::endl;
        Fileout << "*END FUNCTION inputb " << std::endl;
        Fileout << "* " << std::endl;
        Fileout << "*************************" << std::endl;
        Fileout << "*FUNCTION outputb " << std::endl;
        Fileout << "17 : ST 3, -1(1)Store return address" << std::endl;
        Fileout << "18 : LD 3, -2(1)Load parameter " << std::endl;
        Fileout << "19 : OUTB 3, 3, 3 Output bool " << std::endl;
        Fileout << "20 : LD 3, -1(1)Load return address" << std::endl;
        Fileout << "21 : LD 1, 0(1)Adjust fp" << std::endl;
        Fileout << "22 : JMP 7, 0(3)Return " << std::endl;
        Fileout << "*END FUNCTION outputb" << std::endl;
        Fileout << "* " << std::endl;
        Fileout << "*************************" << std::endl;
        Fileout << "*FUNCTION inputc " << std::endl;
        Fileout << "23 : ST 3, -1(1)Store return address" << std::endl;
        Fileout << "24 : INC 2, 2, 2 Grab char input " << std::endl;
        Fileout << "25 : LD 3, -1(1)Load return address" << std::endl;
        Fileout << "26 : LD 1, 0(1)Adjust fp" << std::endl;
        Fileout << "27 : JMP 7, 0(3)Return" << std::endl;
        Fileout << "*END FUNCTION inputc" << std::endl;
        Fileout << "* " << std::endl;
        Fileout << "*************************" << std::endl;
        Fileout << "*FUNCTION outputc " << std::endl;
        Fileout << "28 : ST 3, -1(1)Store return address" << std::endl;
        Fileout << "29 : LD 3, -2(1)Load parameter " << std::endl;
        Fileout << "30 : OUTC 3, 3, 3 Output char " << std::endl;
        Fileout << "31 : LD 3, -1(1)Load return address" << std::endl;
        Fileout << "32 : LD 1, 0(1)Adjust fp" << std::endl;
        Fileout << "33 : JMP 7, 0(3)Return" << std::endl;
        Fileout << "*END FUNCTION outputc" << std::endl;
        Fileout << "* " << std::endl;
        Fileout << "*************************" << std::endl;
        Fileout << "*FUNCTION outnl " << std::endl;
        Fileout << "34 : ST 3, -1(1)Store return address" << std::endl;
        Fileout << "35 : OUTNL 3, 3, 3 Output a newline" << std::endl;
        Fileout << "36 : LD 3, -1(1)Load return address" << std::endl;
        Fileout << "37 : LD 1, 0(1)Adjust fp" << std::endl;
        Fileout << "38 : JMP 7, 0(3)Return" << std::endl;
        Fileout << "*END FUNCTION outnl " << std::endl;
        Fileout << "* " << std::endl;
        Fileout << "*************************" << std::endl;
        currentAddr = 39;
}

// Load INIT section of exe
void Init(std::ofstream &Fileout)
{
        Fileout << "*INIT \n";
        Fileout << "0 : JMP 7," << currentAddr - 1 << "(7)     Jmp to init \n";
        Fileout << currentAddr++ << " : LDA 1," << goffset << "(0)  set frist frame (end of globals) \n";
        Fileout << currentAddr++ << " : ST 1,0(1)   Store old fp ()\n";
        Fileout << "* GLOBLS + STATICS (idk how to do this KEKW)\n";
        Fileout << currentAddr++ << " : LDA 3,1(7)  return addr in ac? \n";
        Fileout << "* Main ADDR " << GetAddr("main") << std::endl;
        Fileout << currentAddr++ << " : JMP 7," << -1 * (currentAddr - GetAddr("main")) << "(7)   Jump to main\n";
        Fileout << currentAddr++ << " : HALT 0,0,0 DONE\n";
}

// Generate Code using tree
void GenerateCodeTree(treeNode *Node, std::ofstream &Fileout, bool PushParam)
{
        if (Node == NULL)
        {
                return;
        }
        int OldToff = TOFF;

        switch (Node->Kind())
        {
        case DeclK:
                switch (Node->DKind())
                {
                case VarK:
                        // Local Arrays
                        if (Node->ArrayIs())
                        {
                                if (Node->StaticIs() || Node->GlobablIs())
                                {
                                        Fileout << currentAddr++ << " : "
                                                << "LDC " << AC1 << "," << Node->GetSize() - 1 << "(0)"
                                                << "    LOAD SIZE of ARRAY" << std::endl;
                                        Fileout << currentAddr++ << " : "
                                                << "ST " << AC1 << "," << Node->GetLoc() + 1 << "(" << GLOBAL << ")"
                                                << " Save Array Size" << std::endl;
                                }
                                else
                                {
                                        Fileout << currentAddr++ << " : "
                                                << "LDC " << AC1 << "," << Node->GetSize() - 1 << "(0)"
                                                << "    LOAD SIZE of ARRAY" << std::endl;
                                        Fileout << currentAddr++ << " : "
                                                << "ST " << AC1 << "," << Node->GetLoc() + 1 << "(" << FRAMEPOINTER << ")"
                                                << " Save Array Size" << std::endl;
                                }
                        }
                        break;
                case FuncK:
                        Fileout << "* ** ** ** ** ** ** ** ** ** ** ** ** \n";
                        Fileout << "* FUNC " << Node->token()->tokenstr << std::endl;
                        TOFF = Node->GetSize();
                        Fileout << "* TOFF = " << TOFF << std::endl;

                        Node->address = currentAddr;

                        Fileout << currentAddr++ << " : ST  " << AC1 << ",-1"
                                << "(" << FRAMEPOINTER << ")"
                                << " Store Ret Addr" << std::endl;

                        // Generate Code in Children
                        GenerateCodeTree(Node->GetChild(0), Fileout);
                        GenerateCodeTree(Node->GetChild(1), Fileout);

                        // Standard End
                        Fileout << "* add Standard end in case of no return \n";
                        Fileout << currentAddr++ << " : LDC " << RETURN << ",0"
                                << "(0)"
                                << "   Set Ret val to 0" << std::endl;
                        Fileout << currentAddr++ << " : LD " << AC1 << ",-1"
                                << "(" << FRAMEPOINTER << ")"
                                << " Load Return addr" << std::endl;
                        Fileout << currentAddr++ << " : LD " << FRAMEPOINTER << ",0"
                                << "(" << FRAMEPOINTER << ")"
                                << "   Adjust Frame Pointer " << std::endl;
                        Fileout << currentAddr++ << " : JMP " << PC << ",0 "
                                << "(" << AC1 << ")"
                                << "  Ret" << std::endl;

                        Fileout << "* END OF FUNC " << Node->token()->tokenstr << std::endl;

                        break;

                default:
                        break;
                }
                break;
        case StmtK:
                switch (Node->SKind())
                {
                case CompoundK:
                        Fileout << "* COMPOUND" << std::endl;
                        OldToff = TOFF;
                        TOFF = Node->GetSize();
                        Fileout << "* TOFF = " << TOFF << std::endl;

                        GenerateCodeTree(Node->GetChild(0), Fileout);
                        GenerateCodeTree(Node->GetChild(1), Fileout);

                        Fileout << "* End of Compound " << std::endl;
                        TOFF = OldToff;
                        Fileout << "* TOFF = " << TOFF << std::endl;

                        break;
                // Return*************
                case ReturnK:
                        Fileout << "* RETURN" << std::endl;
                        Fileout << currentAddr++ << " : "
                                << "LD " << AC1 << ",-1"
                                << "(" << FRAMEPOINTER << ")"
                                << "    Load return addr" << std::endl;
                        Fileout << currentAddr++ << " : "
                                << "LD " << FRAMEPOINTER << ",0"
                                << "(" << FRAMEPOINTER << ")"
                                << "   Frame Pointer Adjusted" << std::endl;
                        Fileout << currentAddr++ << " : "
                                << "JMP " << PC << ",0"
                                << "(" << AC1 << ")"
                                << " Return" << std::endl;
                        break;

                default:
                        break;
                }

                break;
        case ExpK:
                switch (Node->EKind())
                {
                case OpK:
                        if (PushParam == true)
                        {
                                TOFF--;
                                Fileout << "* TOFF =" << TOFF << std::endl;
                        }
                        Fileout << "* OP " << std::endl;

                        OldToff = TOFF;
                        // Fileout << "* OR" << std::endl;
                        //  Store Left hand side in temp area
                        GenerateCodeTree(Node->GetChild(0), Fileout);
                        // Loading

                        Fileout << "* Loading Left Hand Side" << std::endl;

                        Fileout << currentAddr++ << " : "
                                << "ST " << AC1 << "," << TOFF << "(" << FRAMEPOINTER << ")"
                                << "    Loading LHS (var " << Node->GetChild(0)->token()->tokenstr << ")" << std::endl;
                        TOFF--;
                        Fileout << "* TOFF = " << TOFF << std::endl;

                        // Should be unnesscicary for unary ops, leaving for memes
                        GenerateCodeTree(Node->GetChild(1), Fileout);

                        TOFF = OldToff;
                        Fileout << "* TOFF = " << TOFF << std::endl;

                        // OR
                        if (strcmp(Node->token()->tokenstr, "or") == 0)
                        {
                                Fileout << currentAddr++ << " : "
                                        << "LD " << AC2 << "," << TOFF << "(" << FRAMEPOINTER << ")"
                                        << "   Loading left into AC2" << std::endl;
                                Fileout << currentAddr++ << " : "
                                        << "OR " << AC1 << "," << AC2 << "," << AC1 << "   OR op" << std::endl;
                                Fileout << currentAddr++ << " : "
                                        << "ST " << AC1 << "," << TOFF << "(" << FRAMEPOINTER << ")"
                                        << "   Storing Result" << std::endl;
                        }
                        // AND
                        else if (strcmp(Node->token()->tokenstr, "and") == 0)
                        {
                                Fileout << currentAddr++ << " : "
                                        << "LD " << AC2 << "," << TOFF << "(" << FRAMEPOINTER << ")"
                                        << "   Loading left into AC2" << std::endl;
                                Fileout << currentAddr++ << " : "
                                        << "AND " << AC1 << "," << AC2 << "," << AC1 << "   AND op" << std::endl;
                                Fileout << currentAddr++ << " : "
                                        << "ST " << AC1 << "," << TOFF << "(" << FRAMEPOINTER << ")"
                                        << "   Storing Result" << std::endl;
                        }
                        // Addition
                        else if (strcmp(Node->token()->tokenstr, "+") == 0)
                        {
                                Fileout << currentAddr++ << " : "
                                        << "LD " << AC2 << "," << TOFF << "(" << FRAMEPOINTER << ")"
                                        << "   Loading left into AC2" << std::endl;
                                Fileout << currentAddr++ << " : "
                                        << "ADD " << AC1 << "," << AC2 << "," << AC1 << "   ADD + op" << std::endl;
                                Fileout << currentAddr++ << " : "
                                        << "ST " << AC1 << "," << TOFF << "(" << FRAMEPOINTER << ")"
                                        << "   Storing Result" << std::endl;
                        }
                        // Subtraction
                        else if (strcmp(Node->token()->tokenstr, "-") == 0)
                        {
                                Fileout << currentAddr++ << " : "
                                        << "LD " << AC2 << "," << TOFF << "(" << FRAMEPOINTER << ")"
                                        << "   Loading left into AC2" << std::endl;
                                Fileout << currentAddr++ << " : "
                                        << "SUB " << AC1 << "," << AC2 << "," << AC1 << "   SUB - op" << std::endl;
                                Fileout << currentAddr++ << " : "
                                        << "ST " << AC1 << "," << TOFF << "(" << FRAMEPOINTER << ")"
                                        << "   Storing Result" << std::endl;
                        }
                        // Multiplication
                        else if (strcmp(Node->token()->tokenstr, "*") == 0)
                        {
                                Fileout << currentAddr++ << " : "
                                        << "LD " << AC2 << "," << TOFF << "(" << FRAMEPOINTER << ")"
                                        << "   Loading left into AC2" << std::endl;
                                Fileout << currentAddr++ << " : "
                                        << "MUL " << AC1 << "," << AC2 << "," << AC1 << "   MUL * op" << std::endl;
                                Fileout << currentAddr++ << " : "
                                        << "ST " << AC1 << "," << TOFF << "(" << FRAMEPOINTER << ")"
                                        << "   Storing Result" << std::endl;
                        }
                        // Div
                        else if (strcmp(Node->token()->tokenstr, "/") == 0)
                        {
                                Fileout << currentAddr++ << " : "
                                        << "LD " << AC2 << "," << TOFF << "(" << FRAMEPOINTER << ")"
                                        << "   Loading left into AC2" << std::endl;
                                Fileout << currentAddr++ << " : "
                                        << "DIV " << AC1 << "," << AC2 << "," << AC1 << "   DIV / op" << std::endl;
                                Fileout << currentAddr++ << " : "
                                        << "ST " << AC1 << "," << TOFF << "(" << FRAMEPOINTER << ")"
                                        << "   Storing Result" << std::endl;
                        }
                        // Mod
                        else if (strcmp(Node->token()->tokenstr, "%") == 0)
                        {
                                Fileout << currentAddr++ << " : "
                                        << "LD " << AC2 << "," << TOFF << "(" << FRAMEPOINTER << ")"
                                        << "   Loading left into AC2" << std::endl;
                                Fileout << currentAddr++ << " : "
                                        << "MOD " << AC1 << "," << AC2 << "," << AC1 << "   MOD %% op" << std::endl;
                                Fileout << currentAddr++ << " : "
                                        << "ST " << AC1 << "," << TOFF << "(" << FRAMEPOINTER << ")"
                                        << "   Storing Result" << std::endl;
                        }
                        //
                        else if (strcmp(Node->token()->tokenstr, "<") == 0)
                        {
                                Fileout << currentAddr++ << " : "
                                        << "LD " << AC2 << "," << TOFF << "(" << FRAMEPOINTER << ")"
                                        << "   Loading left into AC2" << std::endl;
                                Fileout << currentAddr++ << " : "
                                        << "TLT " << AC1 << "," << AC2 << "," << AC1 << "   TLC < op" << std::endl;
                                Fileout << currentAddr++ << " : "
                                        << "ST " << AC1 << "," << TOFF << "(" << FRAMEPOINTER << ")"
                                        << "   Storing Result" << std::endl;
                        }
                        else if (strcmp(Node->token()->tokenstr, "<=") == 0)
                        {
                                Fileout << currentAddr++ << " : "
                                        << "LD " << AC2 << "," << TOFF << "(" << FRAMEPOINTER << ")"
                                        << "   Loading left into AC2" << std::endl;
                                Fileout << currentAddr++ << " : "
                                        << "TLE " << AC1 << "," << AC2 << "," << AC1 << "   TLE <= op" << std::endl;
                                Fileout << currentAddr++ << " : "
                                        << "ST " << AC1 << "," << TOFF << "(" << FRAMEPOINTER << ")"
                                        << "   Storing Result" << std::endl;
                        }
                        else if (strcmp(Node->token()->tokenstr, ">") == 0)
                        {
                                Fileout << currentAddr++ << " : "
                                        << "LD " << AC2 << "," << TOFF << "(" << FRAMEPOINTER << ")"
                                        << "   Loading left into AC2" << std::endl;
                                Fileout << currentAddr++ << " : "
                                        << "TGT " << AC1 << "," << AC2 << "," << AC1 << "   TLE > op" << std::endl;
                                Fileout << currentAddr++ << " : "
                                        << "ST " << AC1 << "," << TOFF << "(" << FRAMEPOINTER << ")"
                                        << "   Storing Result" << std::endl;
                        }
                        else if (strcmp(Node->token()->tokenstr, ">=") == 0)
                        {
                                Fileout << currentAddr++ << " : "
                                        << "LD " << AC2 << "," << TOFF << "(" << FRAMEPOINTER << ")"
                                        << "   Loading left into AC2" << std::endl;
                                Fileout << currentAddr++ << " : "
                                        << "TGE " << AC1 << "," << AC2 << "," << AC1 << "   TGE >= op" << std::endl;
                                Fileout << currentAddr++ << " : "
                                        << "ST " << AC1 << "," << TOFF << "(" << FRAMEPOINTER << ")"
                                        << "   Storing Result" << std::endl;
                        }
                        // Equals
                        else if (strcmp(Node->token()->tokenstr, "==") == 0)
                        {
                                Fileout << currentAddr++ << " : "
                                        << "LD " << AC2 << "," << TOFF << "(" << FRAMEPOINTER << ")"
                                        << "   Loading left into AC2" << std::endl;
                                Fileout << currentAddr++ << " : "
                                        << "TEQ " << AC1 << "," << AC2 << "," << AC1 << "   == Equals op" << std::endl;
                                Fileout << currentAddr++ << " : "
                                        << "ST " << AC1 << "," << TOFF << "(" << FRAMEPOINTER << ")"
                                        << "   Storing Result" << std::endl;
                        }
                        else if (strcmp(Node->token()->tokenstr, "!=") == 0)
                        {
                                Fileout << currentAddr++ << " : "
                                        << "LD " << AC2 << "," << TOFF << "(" << FRAMEPOINTER << ")"
                                        << "   Loading left into AC2" << std::endl;
                                Fileout << currentAddr++ << " : "
                                        << "TNE " << AC1 << "," << AC2 << "," << AC1 << "   != Not Equals op" << std::endl;
                                Fileout << currentAddr++ << " : "
                                        << "ST " << AC1 << "," << TOFF << "(" << FRAMEPOINTER << ")"
                                        << "   Storing Result" << std::endl;
                        }
                        // Not
                        else if (strcmp(Node->token()->tokenstr, "not") == 0)
                        {
                                Fileout << currentAddr++ << " : "
                                        << "LD " << AC2 << "," << TOFF << "(" << FRAMEPOINTER << ")"
                                        << "   Loading left (only opperand?) into AC2" << std::endl;
                                Fileout << currentAddr++ << " : "
                                        << "LDC " << AC1 << "," << 1 << "(0)"
                                        << "   Loading 1 into AC1" << std::endl;
                                Fileout << currentAddr++ << " : "
                                        << "XOR " << AC1 << "," << AC2 << "," << AC1 << "   XPR not op" << std::endl;
                                Fileout << currentAddr++ << " : "
                                        << "ST " << AC1 << "," << TOFF << "(" << FRAMEPOINTER << ")"
                                        << "   Storing Result" << std::endl;
                        }
                        // Rand
                        else if (strcmp(Node->token()->tokenstr, "?") == 0)
                        {
                                Fileout << currentAddr++ << " : "
                                        << "LD " << AC2 << "," << TOFF << "(" << FRAMEPOINTER << ")"
                                        << "   Loading left (only opperand?) into AC2" << std::endl;
                                Fileout << currentAddr++ << " : "
                                        << "RND " << AC1 << "," << AC2 << "," << AC1 << "   ? RND op" << std::endl;
                                Fileout << currentAddr++ << " : "
                                        << "ST " << AC1 << "," << TOFF << "(" << FRAMEPOINTER << ")"
                                        << "   Storing Result" << std::endl;
                        }
                        else if (strcmp(Node->token()->tokenstr, "chsign") == 0)
                        {
                                Fileout << currentAddr++ << " : "
                                        << "LD " << AC2 << "," << TOFF << "(" << FRAMEPOINTER << ")"
                                        << "   Loading left (only opperand?) into AC2" << std::endl;
                                Fileout << currentAddr++ << " : "
                                        << "NEG " << AC1 << "," << AC2 << "," << AC1 << "   NEG chsign op" << std::endl;
                                Fileout << currentAddr++ << " : "
                                        << "ST " << AC1 << "," << TOFF << "(" << FRAMEPOINTER << ")"
                                        << "   Storing Result" << std::endl;
                        }
                        else if (strcmp(Node->token()->tokenstr, "[") == 0)
                        {
                                int LOC = Node->GetChild(0)->GetLoc();

                                // Probably unnsecassry?? Loads (Size?) into AC2 for ikd why
                                Fileout << currentAddr++ << " : "
                                        << "LD " << AC2 << "," << TOFF << "(" << FRAMEPOINTER << ")"
                                        << "   Loading left (???) into AC2" << std::endl;

                                // Store value at array in case that is really whats wanted
                                //
                                if (Node->GetChild(0)->MEMTYPE == "Global" || Node->GetChild(0)->MEMTYPE == "LocalStatic")
                                {
                                        Fileout << "* Global or LocalStatic Array" << std::endl;
                                        Fileout << currentAddr++ << " : "
                                                << "LDA " << AC4 << "," << LOC << "(" << GLOBAL << ")"
                                                << "     Load address of base" << std::endl;
                                        Fileout << currentAddr++ << " : "
                                                << "SUB " << AC4 << "," << AC4 << "," << AC1 << "       Compute offset value" << std::endl;
                                        // Fileout << currentAddr++ << " : " << "ST " << AC1 << ",0" << "(" << AC4 << ") Store AC1 in array" << std::endl;
                                }
                                else
                                {
                                        Fileout << "* Loacl Array" << std::endl;
                                        Fileout << currentAddr++ << " : "
                                                << "LDA " << AC4 << "," << LOC << "(" << FRAMEPOINTER << ")"
                                                << "     Load address of base" << std::endl;
                                        Fileout << currentAddr++ << " : "
                                                << "SUB " << AC4 << "," << AC4 << "," << AC1
                                                << "       Compute offset value" << std::endl;
                                }
                                // Store Value At Location
                                /* Fileout << currentAddr++ << " : "
                                        << "ST " << AC1 << ",0"
                                        << "(" << AC4 << ") Store AC1 in array" << std::endl; */
                                // Store Value in AC1 becuase IDK seems like somthing i should do??
                                Fileout << currentAddr++ << " : "
                                        << "LD " << AC1 << ",0"
                                        << "(" << AC4 << ")"
                                        << "   Storing Array Value in AC1" << std::endl;
                        }
                        TOFF--;
                        Fileout << "* TOFF = " << TOFF << std::endl;

                        if (PushParam == true)
                        {
                                Fileout << currentAddr++ << " : "
                                        << "ST " << AC1 << "," << TOFF << "(" << FRAMEPOINTER << ")"
                                        << "    Push Param" << std::endl;
                        }

                        //TOFF--;
                       // Fileout << "* TOFF = " << TOFF << std::endl;

                        break;
                case AssingK:
                        if (PushParam == true)
                        {
                                TOFF--;
                                Fileout << "* TOFF =" << TOFF << std::endl;
                        }
                        Fileout << "* Assing Op" << std::endl;

                        OldToff = TOFF;
                        // Fileout << "* OR" << std::endl;
                        //  Store Left hand side in temp area
                        Fileout << "* Left hand side in AC1" << std::endl;
                        GenerateCodeTree(Node->GetChild(0), Fileout);
                        // Loading

                        Fileout << "* Storing Left Hand Side" << std::endl;

                        Fileout << currentAddr++ << " : "
                                << "ST " << AC1 << "," << TOFF << "(" << FRAMEPOINTER << ")"
                                << "    Loading LHS (var " << Node->GetChild(0)->token()->tokenstr << ")" << std::endl;
                        TOFF--;
                        Fileout << "* TOFF = " << TOFF << std::endl;

                        // Should be unnesscicary for unary ops, leaving for memes
                        // Right Hand Side
                        Fileout << "* Loading Right Hand Side" << std::endl;
                        GenerateCodeTree(Node->GetChild(1), Fileout);

                        TOFF++;
                        Fileout << "* TOFF = " << TOFF << std::endl;

                        if (strcmp(Node->token()->tokenstr, "+=") == 0)
                        {
                                Fileout << currentAddr++ << " : "
                                        << "LD " << AC2 << "," << TOFF << "(" << FRAMEPOINTER << ")"
                                        << "   Loading left into AC2" << std::endl;
                                Fileout << currentAddr++ << " : "
                                        << "ADD " << AC1 << "," << AC2 << "," << AC1 << "   ADD += op" << std::endl;
                        }
                        else if (strcmp(Node->token()->tokenstr, "-=") == 0)
                        {
                                Fileout << currentAddr++ << " : "
                                        << "LD " << AC2 << "," << TOFF << "(" << FRAMEPOINTER << ")"
                                        << "   Loading left into AC2" << std::endl;
                                Fileout << currentAddr++ << " : "
                                        << "SUB " << AC1 << "," << AC2 << "," << AC1 << "   ADD -= op" << std::endl;
                        }
                        else if (strcmp(Node->token()->tokenstr, "++") == 0)
                        {
                                Fileout << "* INC OPERATOR" << std::endl;
                                Fileout << currentAddr++ << " : "
                                        << "LD " << AC2 << "," << TOFF << "(" << FRAMEPOINTER << ")"
                                        << "   Loading left into AC2" << std::endl;
                                Fileout << currentAddr++ << " : "
                                        << "LDC " << AC1 << "," << 1 << "(0)"
                                        << "   Loading 1 into AC1" << std::endl;
                                Fileout << currentAddr++ << " : "
                                        << "ADD " << AC1 << "," << AC2 << "," << AC1 << "   ADD ++ op" << std::endl;
                        }
                        else if (strcmp(Node->token()->tokenstr, "--") == 0)
                        {
                                Fileout << "* DEC OPERATOR" << std::endl;
                                Fileout << currentAddr++ << " : "
                                        << "LD " << AC2 << "," << TOFF << "(" << FRAMEPOINTER << ")"
                                        << "   Loading left (only?) into AC2" << std::endl;
                                Fileout << currentAddr++ << " : "
                                        << "LDC " << AC1 << "," << 1 << "(0)"
                                        << "   Loading 1 into AC1" << std::endl;
                                Fileout << currentAddr++ << " : "
                                        << "SUB " << AC1 << "," << AC2 << "," << AC1 << "   SUB -- op" << std::endl;
                        }
                        else if (strcmp(Node->token()->tokenstr, "=") == 0)
                        {
                                // Do nothing because Right Hand side is in AC1
                        }

                        // Store Value in Left Child
                        // If assing to array location
                        if (strcmp(Node->GetChild(0)->token()->tokenstr, "[") == 0)
                        {
                                // AC1 SHOULD have the value i want to store
                                // AC4 SHOULD have the address i want to store
                                Fileout << "* Assinging to array Location" << std::endl;
                                Fileout << currentAddr++ << " : "
                                        << "ST " << AC1 << ",0"
                                        << "(" << AC4 << ") Store AC1 in array" << std::endl;
                        }
                        // If just a normal var
                        else
                        {
                                Fileout << "* Variable" << Node->GetChild(0)->token()->tokenstr << " LOC is " << Node->GetChild(0)->GetLoc() << std::endl;
                                if (Node->GetChild(0)->MEMTYPE == "Global" || Node->GetChild(0)->MEMTYPE == "LocalStatic")
                                {
                                        Fileout << "* Global or LocalStatic Var" << std::endl;
                                        Fileout << currentAddr++ << " : "
                                                << "ST " << AC1 << "," << Node->GetChild(0)->GetLoc() << "(" << GLOBAL << ")"
                                                << "    Loading LHS (var " << Node->GetChild(0)->token()->tokenstr << ")" << std::endl;
                                }
                                else
                                {
                                        Fileout << "* Local or Parmaets Var" << std::endl;

                                        Fileout << currentAddr++ << " : "
                                                << "ST " << AC1 << "," << Node->GetChild(0)->GetLoc() << "(" << FRAMEPOINTER << ")"
                                                << "    Loading LHS (var " << Node->GetChild(0)->token()->tokenstr << ")" << std::endl;
                                }
                        }
                        //****Push Param
                        TOFF = OldToff;
                        Fileout << "* TOFF = " << TOFF << std::endl;

                        if (PushParam == true)
                        {
                                Fileout << currentAddr++ << " : "
                                        << "ST " << AC1 << "," << TOFF << "(" << FRAMEPOINTER << ")"
                                        << "    Push Param" << std::endl;
                        }
                        Fileout << "* End Assing Op" << std::endl;

                        break;

                case constantK:
                        Fileout << "* CONST" << std::endl;
                        // Load into AC1 (Might need to make a few diffrent ones?)
                        switch (Node->EType())
                        {
                        case Integer:
                                // Dec TOFF to gve room for Param
                                if (PushParam == true)
                                {
                                        TOFF--;
                                        Fileout << "* TOFF =" << TOFF << std::endl;
                                }
                                Fileout << currentAddr++ << " : "
                                        << "LDC " << AC1 << "," << Node->token()->nvalue << "(0)"
                                        << "Load Integer Const" << std::endl;
                                // Push Param
                                if (PushParam == true)
                                {
                                        Fileout << currentAddr++ << " : "
                                                << "ST " << AC1 << "," << TOFF << "(" << FRAMEPOINTER << ")"
                                                << "    Push Param" << std::endl;
                                }
                                break;
                        case Char:
                                // Dec TOFF to gve room for Param
                                if (PushParam == true)
                                {
                                        TOFF--;
                                        Fileout << "* TOFF =" << TOFF << std::endl;
                                }
                                Fileout << currentAddr++ << " : "
                                        << "LDC " << AC1 << ","
                                        << "\'" << Node->token()->cvalue << "\'"
                                        << "(0)"
                                        << "Load Char Const" << std::endl;
                                // Push Param
                                if (PushParam == true)
                                {
                                        Fileout << currentAddr++ << " : "
                                                << "ST " << AC1 << "," << TOFF << "(" << FRAMEPOINTER << ")"
                                                << "    Push Param" << std::endl;
                                }
                                break;
                        case boolean:
                                // Dec TOFF to gve room for Param
                                if (PushParam == true)
                                {
                                        TOFF--;
                                        Fileout << "* TOFF =" << TOFF << std::endl;
                                }
                                Fileout << currentAddr++ << " : "
                                        << "LDC " << AC1 << "," << Node->token()->nvalue << "(0)"
                                        << "Load BOOL Const" << std::endl;
                                // Push Param
                                if (PushParam == true)
                                {
                                        Fileout << currentAddr++ << " : "
                                                << "ST " << AC1 << "," << TOFF << "(" << FRAMEPOINTER << ")"
                                                << "    Push Param" << std::endl;
                                }
                                break;

                        default:
                                break;
                        }
                        Fileout << "* End CONST" << std::endl;
                        break;
                // IDs************
                case IdK:
                        Fileout << "* ID" << std::endl;
                        // Load into AC1 (Might need to make a few diffrent ones?)

                        // Dec TOFF to gve room for Param
                        if (PushParam == true)
                        {
                                TOFF--;
                                Fileout << "* (ID) TOFF =" << TOFF << std::endl;
                        }
                        if (Node->MEMTYPE == "Global" || Node->MEMTYPE == "LocalStatic")
                        {
                                Fileout << "* Global or LocalStatic Var" << std::endl;
                                Fileout << currentAddr++ << " : "
                                        << "LD " << AC1 << "," << Node->GetLoc() << "(" << GLOBAL << ")"
                                        << "    Load Variable " << Node->token()->tokenstr << std::endl;
                        }
                        else
                        {
                                Fileout << "* Local or Parm Var" << std::endl;
                                Fileout << currentAddr++ << " : "
                                        << "LD " << AC1 << "," << Node->GetLoc() << "(" << FRAMEPOINTER << ")"
                                        << "    Load Variable " << Node->token()->tokenstr << std::endl;
                        }
                        // Push Param
                        if (PushParam == true)
                        {
                                Fileout << currentAddr++ << " : "
                                        << "ST " << AC1 << "," << TOFF << "(" << FRAMEPOINTER << ")"
                                        << "    Push Param" << std::endl;
                        }

                        Fileout << "* End ID" << std::endl;
                        break;
                // CALL*************
                case CallK:
                        Fileout << "* CALL output" << std::endl;
                        Fileout << currentAddr++ << " : "
                                << "ST " << FRAMEPOINTER << "," << TOFF << "(" << FRAMEPOINTER << ")"
                                << " FP in ghost frame for output" << std::endl;
                        // Save Old Toff
                        OldToff = TOFF;
                        TOFF--;
                        Fileout << "* TOFF =" << TOFF << std::endl;
                        // Load Params
                        Fileout << "* Loading Parms" << std::endl;
                        GenerateCodeTree(Node->GetChild(0), Fileout, true);
                        // Jmp to Code
                        // activate ghost frame GIGAHAS
                        Fileout << currentAddr++ << " : "
                                << "LDA " << FRAMEPOINTER << "," << OldToff << "(" << FRAMEPOINTER << ")"
                                << "    Ghost Frame become new active frame" << std::endl;
                        Fileout << currentAddr++ << " : "
                                << "LDA " << AC1 << ",1"
                                << "(" << PC << ")"
                                << "   Return addr in AC" << std::endl;
                        Fileout << "* Func addr: " << GetAddr(Node->token()->tokenstr) << std::endl;
                        Fileout << currentAddr++ << " : "
                                << "JMP " << PC << ","
                                << -1 * (currentAddr - GetAddr(Node->token()->tokenstr)) << "(" << PC << ")"
                                << "    Call " << Node->token()->tokenstr << std::endl;
                        Fileout << currentAddr++ << " : "
                                << "LDA " << AC1 << ",0"
                                << "(" << RETURN << ")"
                                << "  Save result in AC1" << std::endl;

                        Fileout << "* End Call" << std::endl;
                        TOFF = OldToff;
                        Fileout << "* TOFF = " << TOFF << std::endl;

                        break;
                default:
                        break;
                }
                break;
        default:
                break;
        }
        GenerateCodeTree(Node->nextSibling(), Fileout, PushParam);
}