package edu.colorado.csci3155.mython

/*--
    We will define the expression evaluation functions in this object.
 */

object EvaluateExpression {

    /*TODO: Complete this */
    def evalExpr(e: Expr, env: Map[String, Int], store: MythonStore): MythonValue = e match {
        case ConstNum(d) => NumValue(d)
        case Ident(s) => {
            if (env.contains(s)) {
                NumValue(env(s).toDouble)
            } else {
                throw new IllegalArgumentException("Not found identifier")
            }
        }
        case Plus(e1, e2) => {
            val v1 = evalExpr(e1, env, store)
            val v2 = evalExpr(e2, env, store)
            (v1, v2) match {
                case (NumValue(v1), NumValue(v2)) => NumValue(v1 + v2)
                case _ => throw new IllegalArgumentException("plus failed")
            }

        }
        case Minus(e1, e2) => {
            val v1 = evalExpr(e1, env, store)
            val v2 = evalExpr(e2, env, store)
            (v1, v2) match {
                case (NumValue(v1), NumValue(v2)) => NumValue(v1 - v2)
                case _ => throw new IllegalArgumentException("minus failed")
            }
        }
        case Mult(e1, e2) => {
            val v1 = evalExpr(e1, env, store)
            val v2 = evalExpr(e2, env, store)
            (v1, v2) match {
                case (NumValue(v1), NumValue(v2)) => NumValue(v1 * v2)
                case _ => throw new IllegalArgumentException("mult failed")
            }
        }
        case Div(e1, e2) => {
            val v1 = evalExpr(e1, env, store)
            val v2 = evalExpr(e2, env, store)
            (v1, v2) match {
                case (NumValue(v1), NumValue(v2)) if v2 != 0 => NumValue(v1 / v2)
                case (NumValue(v1), NumValue(v2)) => throw RunTimeError("Div by zero")
                case _ => throw new IllegalArgumentException("plus failed")
            }
        }
    }

    /*TODO: Complete this */
    def evalCondExpr(e: CondExpr, env: Map[String, Int], store: MythonStore): Boolean = e match {
        case ConstFalse => false
        case ConstTrue => true
        case Geq(e1, e2) => {
            val v1 = evalExpr(e1, env, store)
            val v2 = evalExpr(e2, env, store)
            (v1, v2) match {
                case (NumValue(v1), NumValue(v2)) => v1 >= v2
                case _ => throw new IllegalArgumentException("invalid nums")
            }
        }
        case Leq(e1, e2) => {
            val v1 = evalExpr(e1, env, store)
            val v2 = evalExpr(e2, env, store)
            (v1, v2) match {
                case (NumValue(v1), NumValue(v2)) => v1 <= v2
                case _ => throw new IllegalArgumentException("invalid nums")
            }
        }
        case Eq(e1, e2) => {
            val v1 = evalExpr(e1, env, store)
            val v2 = evalExpr(e2, env, store)
            (v1, v2) match {
                case (NumValue(v1), NumValue(v2)) => v1 == v2
                case _ => throw new IllegalArgumentException("invalid nums")
            }
        }
        case And(e1, e2) => {
            val v1 = evalCondExpr(e1, env, store)
            val v2 = evalCondExpr(e2, env, store)
            v1 && v2

        }
        case Or(e1, e2) => {
            val v1 = evalCondExpr(e1, env, store)
            val v2 = evalCondExpr(e2, env, store)
            v1 || v2
        }
        case Not(e1)=> {
            ! evalCondExpr(e1, env, store)
        }

    }
}
