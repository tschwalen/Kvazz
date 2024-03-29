#pragma once
#include "asteval.h"
#include "ast.h"
#include <memory>

void run_ast_interpreter(std::shared_ptr<BaseNode> ast);

bool is_gnr(KvazzResult &kr);

LookupResult lookup(std::string identifier, std::shared_ptr<Env> env);

class Interpreter : public AstEvaluator {
private:
    bool lvalue_flag = false;

public:
    virtual KvazzResult eval(BaseNode *node, std::shared_ptr<Env> env) override;
    virtual KvazzResult eval(Program *node, std::shared_ptr<Env> env) override;
    virtual KvazzResult eval(Block *node, std::shared_ptr<Env> env) override;
    virtual KvazzResult eval(AssignOp *node, std::shared_ptr<Env> env) override;
    virtual KvazzResult eval(Declare *node, std::shared_ptr<Env> env) override;
    virtual KvazzResult eval(FunctionDeclare *node, std::shared_ptr<Env> env) override;
    virtual KvazzResult eval(Return *node, std::shared_ptr<Env> env) override;
    virtual KvazzResult eval(IfThen *node, std::shared_ptr<Env> env) override;
    virtual KvazzResult eval(IfElse *node, std::shared_ptr<Env> env) override;
    virtual KvazzResult eval(While *node, std::shared_ptr<Env> env) override;
    virtual KvazzResult eval(BinaryOp *node, std::shared_ptr<Env> env) override;
    virtual KvazzResult eval(UnaryOp *node, std::shared_ptr<Env> env) override;
    virtual KvazzResult eval(FunctionCall *node, std::shared_ptr<Env> env) override;
    virtual KvazzResult eval(Access *node, std::shared_ptr<Env> env) override;
    virtual KvazzResult eval(VariableLookup *node, std::shared_ptr<Env> env) override;
    virtual KvazzResult eval(IntLiteral *node, std::shared_ptr<Env> env) override;
    virtual KvazzResult eval(BoolLiteral *node, std::shared_ptr<Env> env) override;
    virtual KvazzResult eval(RealLiteral *node, std::shared_ptr<Env> env) override;
    virtual KvazzResult eval(StringLiteral *node, std::shared_ptr<Env> env) override;
    virtual KvazzResult eval(VectorLiteral *node, std::shared_ptr<Env> env) override;
};
