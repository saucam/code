import scala.io.StdIn._
import scala.math._

object Main {
  def main(args: Array[String]): Unit = {
    val t = readInt
    (0 until t).foreach { _ =>
       val nq = readLine.split(" ").map(_.toInt)
       val n = nq.head
       val a = readLine.split(" ").map(_.toLong)
       val d1 = new Array[Long](n + 1)
       val d2 = new Array[Long](n + 1)
       d1(0) = -(300000 + 1)
       d2(0) = 0
       var i = 0
       for (k <- a) {
         d1(i + 1) = max(d1(i), d2(i) + k)
         d2(i + 1) = max(d2(i), d1(i) - k)
         i = i + 1
       }
       println(max(d1(n), d2(n)))
    }
  }
}
