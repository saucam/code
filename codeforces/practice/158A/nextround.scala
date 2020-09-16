import scala.io.StdIn._

object Main {
  def main(args: Array[String]): Unit = {
    val nk = readLine.split(" ").map(_.toInt)
    val n = nk.head
    val k = nk.last
    val c = readLine.split(" ").map(_.toInt)
    val t = c(k - 1)
    println(c.filter(e => e > 0 && e >= t).size)
  }
}
