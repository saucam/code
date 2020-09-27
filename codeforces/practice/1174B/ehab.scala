import scala.io.StdIn._

object Main {
  def main(args: Array[String]): Unit = {
    val n = readInt
    val a = readLine.split(" ").map(_.toInt)
    val ans = if (a.exists(x => (x & 0x01) == 1) && a.exists(x => (x & 0x01) == 0)) a.sorted else a
    println(ans.mkString(" "))
  }
}
