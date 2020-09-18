import scala.io.StdIn._

object Main {
  def main(args: Array[String]): Unit = {
    val t = readInt
    (0 until t).foreach { i =>
      val n = readInt
      val arrWithIndex = readLine.split(" ").map(_.toInt).zipWithIndex.toList
      val even = arrWithIndex.filter(x => (x._1 % 2) == 0)
      val evenG = even.grouped(2).toList
      val odd = arrWithIndex.filter(x => (x._1 % 2) != 0)
      val oddG = odd.grouped(2).toList
      val evenPairs = (if ((even.size % 2) != 0) evenG.dropRight(1) else evenG) map { case List((x1, x2), (y1, y2)) => (x2, y2) }
      val oddPairs = (if ((odd.size % 2) != 0) oddG.dropRight(1) else oddG) map { case List((x1, x2), (y1, y2)) => (x2, y2) }
      val result = evenPairs ++ oddPairs
      val finalResult = if (result.size > n - 1) result.dropRight(1) else result
      finalResult foreach { k => println(s"${k._1 + 1} ${k._2 + 1}") }
    }
  }
}
