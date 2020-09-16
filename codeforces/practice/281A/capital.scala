import scala.io.StdIn._

object Main {
  def main(args: Array[String]): Unit = {
    val s = readLine
    println(s"${s.toUpperCase.head}${s.tail}")
  }
}
