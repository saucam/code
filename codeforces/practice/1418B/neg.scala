import scala.io.StdIn._

object Main {
  def main(args: Array[String]): Unit = {
    val t = readInt
    (0 until t).foreach { m =>
      val n = readInt
      val arr = readLine.split(" ").map(_.toInt)
      val l = readLine.split(" ").map(_.toInt)
      val unlocked = (arr zip l).filter(x => x._2 == 0).map(_._1).sortBy(x => -x)
      var k = -1
      val result: Array[Int] = arr.zipWithIndex.map { case (e, i) =>
        if (l(i) == 0) {
          k += 1
          unlocked(k)
        } else {
          e
        }
      }
      println(result.mkString(" "))
    }
  }
}
