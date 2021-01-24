package edu.colorado.csci3155.project1

object StackMachineCompiler {

    /*
    sealed trait Expr
    case class Const(f: Double) extends  Expr
    case class Ident(id: String) extends Expr
    case class Plus(e1: Expr, e2: Expr) extends  Expr
    case class Minus(e1: Expr, e2: Expr) extends  Expr
    case class Mult(e1: Expr, e2: Expr) extends  Expr
    case class Div(e1: Expr, e2: Expr) extends  Expr
    case class Exp(e:Expr) extends Expr
    case class Log(e: Expr) extends Expr
    case class Sine(e: Expr) extends Expr
    case class Cosine(e:Expr) extends Expr
    case class Let(ident: String, e1: Expr, e2: Expr) extends Expr
    */

    /* Function compileToStackMachineCode
        Given expression e as input, return a corresponding list of stack machine instructions.
        The type of stack machine instructions are in the file StackMachineEmulator.scala in this same directory
        The type of Expr is in the file Expr.scala in this directory.
     */
    def compileToStackMachineCode(e: Expr): List[StackMachineInstruction] = {
        e match {
            case Const(f) => {
                val lst: List[StackMachineInstruction] = List(PushI(f))
                lst
             }

            case Ident(id) => {
                val lst: List[StackMachineInstruction] = List(StoreI(id))
                lst
            }

            case Plus(e1, e2) => {
                compileToStackMachineCode(e1) ++ compileToStackMachineCode(e2) ++ List(AddI)
            }

            case Minus(e1, e2) => {
                compileToStackMachineCode(e1) ++ compileToStackMachineCode(e2) ++ List(SubI)
            }

            case Mult(e1, e2) => {
                compileToStackMachineCode(e1) ++ compileToStackMachineCode(e2) ++ List(MultI)
            }

            case Div(e1, e2) => {
                compileToStackMachineCode(e1) ++ compileToStackMachineCode(e2) ++ List(DivI)
            }

            case Exp(e) => {
                compileToStackMachineCode(e) ++ List(ExpI)
            }

            case Log(e) => {
                compileToStackMachineCode(e) ++ List(LogI)
            }

            case Sine(e) => {
                compileToStackMachineCode(e) ++ List(SinI)
            }

            case Cosine(e) => {
                compileToStackMachineCode(e) ++ List(CosI)
            }

            case Let(ident, e1, e2) => {
                compileToStackMachineCode(e1) ++ List(LoadI(ident)) ++ compileToStackMachineCode(e2)
            }
        }
    }

}