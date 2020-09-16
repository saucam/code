import scala.io.StdIn._

object Main {
  def main(args: Array[String]): Unit = {
    val n = readInt
    val s = readLine
    var prev = 0
    var ans = 0
    s.foreach { c =>
      if (c == prev) ans += 1;
      prev = c
    }
    println(ans)
  }
}
