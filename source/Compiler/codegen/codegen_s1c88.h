#ifndef CODEGEN_S1C88_H
#define CODEGEN_S1C88_H

#include "source/Compiler/ast/nodebinop.h"
#include "source/Compiler/ast/nodenumber.h"
#include "source/Compiler/ast/nodestring.h"
#include "source/Compiler/ast/nodeunaryop.h"
#include "source/Compiler/ast/nodecompound.h"
#include "source/Compiler/ast/nodevar.h"
#include "source/Compiler/ast/nodeassign.h"
#include "source/Compiler/ast/nodevardecl.h"
#include "source/Compiler/ast/nodeblock.h"
#include "source/Compiler/ast/nodeprogram.h"
#include "source/Compiler/ast/nodevartype.h"
#include "source/Compiler/ast/nodeproceduredecl.h"
#include "source/Compiler/ast/nodeprocedure.h"
#include "source/Compiler/ast/nodeconditional.h"
#include "source/Compiler/ast/nodeforloop.h"
#include "source/Compiler/ast/nodebuiltinmethod.h"
#include "source/Compiler/ast/nodewhileloop.h"
#include "source/Compiler/ast/noderepeatuntil.h"
#include "source/Compiler/ast/nodeasm.h"
#include "source/Compiler/ast/nodebinaryclause.h"
#include "source/Compiler/ast/nodecase.h"
#include "source/Compiler/codegen/methods/abstractmethods.h"
#include "source/Compiler/codegen/abstractcodegen.h"
#include "registerstack.h"
class CodeGenS1C88 : public AbstractCodeGen
{
public:
    CodeGenS1C88();


    void dispatch(QSharedPointer<NodeBinOP>node) override;
//    void dispatchOld(QSharedPointer<NodeBinOP>node) override;
    virtual void dispatch(QSharedPointer<NodeNumber>node) override;
    void dispatch(QSharedPointer<NodeString> node) override;
    void dispatch(QSharedPointer<NodeVarType> node) override;
    void dispatch(QSharedPointer<NodeBinaryClause> node) override;
    void dispatch(QSharedPointer<NodeVar> node) override;
    void dispatch(QSharedPointer<Node> node) override;
    //void dispatch(QSharedPointer<NodeCase> node) override;
    void dispatch(QSharedPointer<NodeRepeatUntil> node) override;
//    void dispatch(QSharedPointer<NodeBuiltinMethod> node) override;
    void dispatch(QSharedPointer<NodeComment> node) override;



    void LoadVariable(QSharedPointer<NodeVar> n) override ;
    QString LoadAddress(QSharedPointer<Node> n) override;
    QString LoadAddress(QSharedPointer<Node> n, QString reg) override;
    void LoadVariable(QSharedPointer<NodeProcedure> node) override;

    virtual void LoadPointer(QSharedPointer<Node> n);
    void LoadVariable(QSharedPointer<Node> n) override;
    void LoadVariable(QSharedPointer<NodeNumber> n) override;
    QString getShift(QSharedPointer<NodeVar> n);


    QString getIndexScaleVal(QSharedPointer<Node> var);

    GenRegisterStack m_reg8 = GenRegisterStack(QStringList({"a","b","l","h"}));
    GenRegisterStack m_reg16 = GenRegisterStack(QStringList({"ba","x1","x2","hl"}));

    QString m_jmp = "jmp ";
    QString m_mov = "mov ";
    QString m_cmp = "cmp ";
    QString m_jne = "jnz ";

    QString getWordByteType( QSharedPointer<Node> n) {
        if (n->isWord(as)) return "word"; else return "byte";
    }

    QString getJmp(bool isOffPage) override {
        return "jmp";
    }
    QString getCallSubroutine() override;
    bool m_isPurePointer = false;


    void ldr (QString x0, QString x1);
    void str (QString x0, QString x1);

    void str(QSharedPointer<Node> var, QString forceReg="");
    void ldr(QSharedPointer<Node> var, QString forceReg="");

    void Binop (QString bop, QString x0, QString x1, QString x2);

    virtual bool UseBlocks() override { return true;}

    QString BinopVariableNumber(QSharedPointer<Node> n, QString value, TokenType::Type type);
    QString getIncbin() override{
        return ".incbin";
    }
    void dispatch(QSharedPointer<NodeVarDecl> node) override;


    virtual QString getJDH8Value(QSharedPointer<Node> n) {
        if (n->isPureVariable() && !n->isReference())
            return "["+n->getValue(as)+"]";
        return n->getValue(as);

    }


    virtual QString getBinaryOperation(QSharedPointer<NodeBinOP> bop);






    void DeclarePointer(QSharedPointer<NodeVarDecl> node) override;



//    void IncBin(Assembler* as, QSharedPointer<NodeVarDecl> node);

    virtual void BuildConditional(QSharedPointer<Node> node,  QString lblSuccess, QString lblFailed, bool page) override;

    virtual void BuildToCmp(QSharedPointer<Node> node);

    virtual void CompareAndJumpIfNotEqualAndIncrementCounter(QSharedPointer<Node> nodeA, QSharedPointer<Node> nodeB, QSharedPointer<Node> step, QString lblJump, bool isOffPage, bool isInclusive) override;
    virtual void CompareAndJumpIfNotEqual(QSharedPointer<Node> nodeA, QSharedPointer<Node> nodeB,QString lblJump, bool isOffpage) override;


    QString getReturn() override;
    QString getReturnInterrupt() override { return "iret";}

    /*
     *
     * Node Assign stuff
     *
     *
     */


    void PrintBop(TokenType::Type type, QString x0, QString x1, QString value, bool is16bit=false);

    void StoreVariable(QSharedPointer<NodeVar> node) override;

    bool StoreVariableSimplified(QSharedPointer<NodeAssign> assignNode) override;

    void AssignString(QSharedPointer<NodeAssign>node) override;

    bool AssignPointer(QSharedPointer<NodeAssign>node) override;

    void GenericAssign(QSharedPointer<NodeAssign> node) override;

    bool IsAssignPointerWithIndex(QSharedPointer<NodeAssign> node) override;

    bool IsAssignArrayWithIndex(QSharedPointer<NodeAssign> node) override;

    bool IsSimpleIncDec(QSharedPointer<NodeAssign> node) override;

    bool IsSimpleAssignPointer(QSharedPointer<NodeAssign>node) override;

    void OptimizeBinaryClause(QSharedPointer<Node> node) override;

    virtual void AssignFromRegister(QSharedPointer<NodeAssign> node) override;

    virtual void AssignToRegister(QSharedPointer<NodeAssign> node) override;




};

#endif // CODEGEN_S1C88_H
