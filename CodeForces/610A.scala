import scala.io.StdIn

// give an integer n, to solve 2a+2b=n and a != b

/**
  * Created by Buffalo on 15/12/29.
  */
object cf_610a {

  def main(args : Array[String]) : Unit = {
    var n = StdIn.readInt()
    if(n % 2 == 1) println("0")
    else if((n/2)%2==1) print(n/2/2)
    else println(n/2/2 - 1)
  }

}
