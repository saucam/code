import scala.io.StdIn._
import scala.collection.immutable._

object Main {
  def main(args: Array[String]): Unit = {
    val t = readInt
    (1 to t).foreach { t =>
      val nk = readLine.split(" ").map(_.toInt)
      val n = nk.head
      val k = nk(1)
      var r = 1
      var cnt = 0
      while(r + cnt <= k) {
        r = r + cnt
        cnt = cnt + 1
      }
      cnt = cnt - 1
      val diff = k - r
      println(s"${"a" * (n - 2 - cnt)}b${"a" * (cnt - diff)}b${"a" * diff}")
    }
  }
}
