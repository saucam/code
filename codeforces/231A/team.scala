import scala.io.StdIn._

object Main {
  def main(args: Array[String]): Unit = {
    val n = readInt
    val ans = (0 until n).map { k =>
       val s = readLine.split(" ").map(_.toInt).sum
       if (s >= 2) 1 else 0
    }.sum
    println(ans)
  }
}
