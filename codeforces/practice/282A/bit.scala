import scala.io.StdIn._

object Main {
  def main(args: Array[String]): Unit = {
    val n = readInt
    val ans = (0 until n).map { k =>
      val op = readLine
      if (op.contains("++")) 1 else -1
    }.sum
    println(ans)
  }
}
