import scala.io.StdIn._

object Main {
  def main(args: Array[String]): Unit = {
    val n = readInt
    (0 until n).foreach { k =>
      val s = readLine
      val result = if (s.length  > 10) s"${s.head}${s.length - 2}${s.last}" else s
      println(result)
    }
  }
}
