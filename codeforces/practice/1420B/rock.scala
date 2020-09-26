import scala.io.StdIn._

object Main {
  def getMS(b: Int): Int = {
    var k = 0;
    var a = b;
    while(a > 0) {
      a = (a >> 1);
      k = k + 1;
    }
    k
  }
  def main(args: Array[String]): Unit = {
    val t = readInt
    (0 until t).foreach { _ =>
      val n = readInt
      val a = readLine.split(" ").map(_.toInt)
      val result: Long = a.groupBy(getMS(_)).map { case (a, b) => (b.size.toLong * (b.size.toLong - 1)) / 2 }.sum 
      println(result)
    }
  }
}
