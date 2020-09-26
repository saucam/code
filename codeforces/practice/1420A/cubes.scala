import scala.io.StdIn._

object Main {
  def main(args: Array[String]): Unit = {
    val t = readInt
    (0 until t).foreach { k =>
       val n = readInt
       val a = readLine.split(" ").map(_.toInt)
       val d = a.sortBy(x => -x)
       if ((d.distinct.size == n) && (d.sameElements(a))) println("NO") else println("YES")
    }
  }
}
