import scala.io.StdIn

/**
  * Created by Buffalo on 16/1/3.
  */
object cf_609a {
  def main(args : Array[String]) = {
    val n :: m :: l = Iterator.continually(StdIn readLine()).takeWhile(_ != null).map(_.toInt).toList

    ((list: List[Int], rem: Int, cnt:Int) => Int = {
      if (rem <= 0) {
        cnt
      } else {
        fun(list.tail, rem - list.head, cnt + 1)
      }
    })
    println(fun(l.sortBy(-_), m, 0))
  }
}
