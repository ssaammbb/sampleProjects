package edu.colorado.csci3155.mython


object EvaluateProgram {


    /* TODO: Implement this.
       1. Create a new environment,
       2. Create a new store
       3. Process each declaration (make a helper function)
       4. Return the final environment and store.
     */

    def dclh(n: Int, decls: List[Declaration], tup: (Map[String, Int], List[MythonValue]), mm: Map[String,Int], mList: List[MythonValue]): (Map[String, Int], List[MythonValue]) = {
        if (n == decls.length) {
            tup
        } else {
            val a: String = decls(n) match{
                case VarDecl(s, e) => {
                    s.toString
                }
                case _ => throw new IllegalArgumentException("error")
            }





            val v: MythonValue = decls(n) match {
                case VarDecl(s, e) => {
                    e match {
                        case ConstNum(d) => NumValue(d)
                        case _ => throw new IllegalArgumentException("error")
                    }
                }
                case _ => throw new IllegalArgumentException("error")
            }
            val nmlist: List[MythonValue] = mList ++ List(v)
            val nv: Int = v match {
                case NumValue(f) => f.toInt
                case _ => throw TypeError("Trying to convert a string to a numeric value")
            }


            val nmap: Map[String,Int] = mm + (a->nv)
            val ntup = (nmap,nmlist)

            dclh(n+1, decls, ntup, nmap, nmlist)
        }
    }

    def makeStore(n: Int, vals: List[MythonValue], msto: MythonStore): MythonStore ={
        if(n == vals.length){
            msto
        }else{
            msto.createNewCell(vals(n))
            makeStore(n+1,vals,msto)
        }
    }

    def evalMultipleDecls(decls: List[Declaration]) : (Map[String, Int], MythonStore) = {
        val m: Map[String,Int] = Map.empty[String,Int]
        val l: List[MythonValue] = List.empty[MythonValue]
        val t = (m,l)
        val eval = dclh(0,decls,t,m,l)


        val msto = new MythonStore
        val stor = makeStore(0,eval._2,msto)

        (eval._1,stor)






        }


    /* TODO: Implement this.

        The single step function takes a list of statements, an environment and
        store (mutable) and returns
        a value (can be UnitValue or value of return expression)
        a list of statements remaining to execute
        Please follow the semantics given in the assignment description.
        Note: that we deviate from the semantics in that Store is a mutable.
     */
    def singleStep(stmtList: List[Statement],
                   env: Map[String, Int],
                   store: MythonStore): (MythonValue, List[Statement]) = {
        val m: MythonValue = NumValue(1.0)
        val l: List[Statement] = List.empty[Statement]
        (m,l)
    }

    def evalProgram(p: Program): MythonValue = {
        p match {
            case Program(decls, stmts) =>
                //1. Initialize environment and store
                val (env, store) = evalMultipleDecls(decls)
                //2. Set the statements remaining.
                var stmtsRemaining: List[Statement] = stmts
                var curVal: MythonValue = UnitValue
                //3. While there are statements remaining
                while (stmtsRemaining.length > 0) {
                    //4. Run a single step
                    val (a:MythonValue, b: List[Statement]) = singleStep(stmtsRemaining, env, store)
                    curVal = a
                    stmtsRemaining = b
                }
                //5. Return the value
                curVal
        }
    }

}
