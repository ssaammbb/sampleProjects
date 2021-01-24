package edu.colorado.csci3155.project1
import scala.annotation.tailrec


/* -- Here are all the instructions to be supported --*/
sealed trait StackMachineInstruction
case class LoadI(s: String) extends StackMachineInstruction
case class  StoreI(s: String) extends StackMachineInstruction
case class PushI(f: Double) extends StackMachineInstruction
case object AddI extends StackMachineInstruction
case object SubI extends StackMachineInstruction
case object MultI extends StackMachineInstruction
case object DivI extends StackMachineInstruction
case object ExpI extends StackMachineInstruction
case object LogI extends StackMachineInstruction
case object SinI extends StackMachineInstruction
case object CosI extends StackMachineInstruction
case object PopI extends StackMachineInstruction


object StackMachineEmulator {



    /* Function emulateSingleInstruction
        Given a list of doubles to represent a stack
              a map from string to double precision numbers for the environment
        and   a single instruction of type StackMachineInstruction
        Return a tuple that contains the
              modified stack that results when the instruction is executed.
              modified environment that results when the instruction is executed.

        Make sure you handle the error cases: eg., stack size must be appropriate for the instruction
        being executed. Division by zero, log of a non negative number
        Throw an exception or assertion violation when error happens.
     */

    /*
    let x: Int = 10 in
        let y: Int = 10 in
            x+y




    */

    def emulateSingleInstruction(stack: List[Double],
                                 env: Map[String, Double],
                                 ins: StackMachineInstruction): (List[Double], Map[String, Double]) = {
        ins match{
            case LoadI(s) => {
                val v = stack(0)
                val ns = stack.drop(1)
                val env2 = env + (s -> v)
                val ans = (ns,env2)
                ans
            }

            case StoreI(s) => {
                if(!env.contains(s)){
                    throw new IllegalArgumentException(
                        s"not in env")
                }else{
                    val v = env(s)
                    val ns = v :: stack
                    val ans = (ns,env)
                    ans
                }
            }

            case PushI(f) => {
                val ns = f :: stack
                val ans = (ns, env)
                ans
            }

            case AddI => {
                if(stack.length == 0){
                    throw new IllegalArgumentException(
                        s"empty stack")
                }
                val v1 = stack(0)
                val ns = stack.drop(1)
                if(ns.length == 0){
                    throw new IllegalArgumentException(
                        s"empty stack")
                }
                val v2 = ns(0)
                val ns2 = ns.drop(1)
                val v3 = v1 + v2
                val ns3 = v3 :: ns2

                val ans = (ns3,env)
                ans

            }

            case SubI => {
                if(stack.length == 0){
                    throw new IllegalArgumentException(
                        s"empty stack")
                }
                val v1 = stack(0)
                val ns = stack.drop(1)
                if(ns.length == 0){
                    throw new IllegalArgumentException(
                        s"empty stack")
                }
                val v2 = ns(0)
                val ns2 = ns.drop(1)
                val v3 = v2 - v1
                val ns3 = v3 :: ns2

                val ans = (ns3,env)
                ans
            }

            case MultI => {
                if(stack.length == 0){
                    throw new IllegalArgumentException(
                        s"empty stack")
                }
                val v1 = stack(0)
                val ns = stack.drop(1)
                if(ns.length == 0){
                    throw new IllegalArgumentException(
                        s"empty stack")
                }
                val v2 = ns(0)
                val ns2 = ns.drop(1)
                val v3 = v1*v2
                val ns3 = v3 :: ns2

                val ans = (ns3,env)
                ans
            }

            case DivI => {
                if(stack.length == 0){
                    throw new IllegalArgumentException(
                        s"empty stack")
                }
                val v1 = stack(0)
                val ns = stack.drop(1)
                if(ns.length == 0){
                    throw new IllegalArgumentException(
                        s"empty stack")
                }
                if(v1 == 0){
                    throw new IllegalArgumentException(
                        s"divide by 0")
                }
                val v2 = ns(0)
                val ns2 = ns.drop(1)
                val v3 = v2/v1
                val ns3 = v3 :: ns2

                val ans = (ns3,env)
                ans
            }

            case ExpI => {
                if(stack.length == 0){
                    throw new IllegalArgumentException(
                        s"empty stack")
                }
                val v1 = stack(0)
                val ns = stack.drop(1)
                val v2 = math.exp(v1)
                val ns2 = v2 :: ns
                val ans = (ns2,env)
                ans
            }

            case LogI => {
                if(stack.length == 0){
                    throw new IllegalArgumentException(
                        s"empty stack")
                }
                val v1 = stack(0)
                if(v1 < 0){
                    throw new IllegalArgumentException(
                        s"log on negative")
                }
                val ns = stack.drop(1)
                val v2 = math.log(v1)
                val ns2 = v2 :: ns
                val ans = (ns2,env)
                ans
            }

            case SinI => {
                if(stack.length == 0){
                    throw new IllegalArgumentException(
                        s"empty stack")
                }
                val v1 = stack(0)
                val ns = stack.drop(1)
                val v2 = math.sin(v1)
                val ns2 = v2 :: ns
                val ans = (ns2,env)
                ans
            }

            case CosI => {
                if(stack.length == 0){
                    throw new IllegalArgumentException(
                        s"empty stack")
                }
                val v1 = stack(0)
                val ns = stack.drop(1)
                val v2 = math.cos(v1)
                val ns2 = v2 :: ns
                val ans = (ns2,env)
                ans
            }

            case PopI => {
                if(stack.length == 0){
                    throw new IllegalArgumentException(
                        s"empty stack")
                }
                val ns = stack.drop(1)
                val ans = (ns,env)
                ans
            }
        }



    }

    /* Function emulateStackMachine
       Execute the list of instructions provided as inputs using the
       emulateSingleInstruction function.
       Use foldLeft over list of instruction rather than a for loop if you can.
       Return value must be the final environment.

       Hint: accumulator for foldLeft must be a tuple (List[Double], Map[String,Double])
             initial value of this accumulator must be (Nil, Map.empty)
             You should use emulateSingleInstruction to update the accmulator.
             It will all fit nicely once you figure it out.
     */


    @tailrec def tailRecFunction(lis: List[StackMachineInstruction], env: Map[String, Double], stack : List[Double]): Map[String,Double] ={
        if(lis.length == 0){
            env
        }else{
            val ns = lis(0)
            val nl = lis.drop(1)
            val tup = emulateSingleInstruction(stack,env,ns)
            val nStack = tup._1
            val nEnv = tup._2
            tailRecFunction(nl,nEnv,nStack)
        }
    }

    def emulateStackMachine(instructionList: List[StackMachineInstruction]): Map[String, Double] =
        {
            var stack : List[Double] = Nil
            var env : Map[String,Double] = Map.empty
            tailRecFunction(instructionList,env,stack)

        }
}