import scala.io.StdIn._

object Main {
  def main(args: Array[String]): Unit = {
    val a = readLine.toUpperCase
    val b = readLine.toUpperCase
    val ans = if (a < b) -1 else if (a > b) 1 else 0
    println(ans)
  }
}
