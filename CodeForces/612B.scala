import scala.io.StdIn

/**
  * Created by Buffalo on 16/1/1.
  */
object cf_612b {

  def main(args : Array[String]): Unit = {
    val n : Int = StdIn readInt()
    val l = StdIn.readLine().split(' ').map(_.toInt).zipWithIndex.sortWith(_._1 < _._1)
    println(0.to(l.size - 2).map(i => Math.abs(l(i)._2.toLong - l(i+1)._2)).sum)
  }

}
