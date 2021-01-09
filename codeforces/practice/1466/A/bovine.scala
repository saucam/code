import scala.io.StdIn._

object Main {
  def main(args: Array[String]): Unit = {
    val t = readInt
    (0 until t).foreach { k =>
      val n = readInt
      val v = readLine.split(" ").map(_.toInt)
      val ans = v.combinations(2).map { case Array(a, b) => (b - a) }.toSet.size
      println(ans)
    } 
  }
}
