import scala.io.StdIn._
import scala.math.abs

object Main {
  def main(args: Array[String]): Unit = {
    val n = (0 until 5).flatMap { r =>
      val c = readLine.split(" ").map(_.toInt)
      c.zipWithIndex.filter { case (c, i) =>
        c == 1
      }.map { case (c, i) => abs(2 - i) + abs(2 - r) }
    }
    println(n.head)
  }
}
