import scala.io.StdIn._

object Main {
  def main(args: Array[String]): Unit = {
    val nm = readLine.split(" ").map(_.toInt)
    val n = nm.head
    val m = nm.last
    val arr = readLine.split(" ").map(_.toInt)
    val visit = new Array[Int](n)
    val result = new Array[Int](n)
    var possible = true
    arr.zipWithIndex.foreach { k =>
      val index = k._2
      if (index > 0) {
        val diff = (k._1 - arr(index - 1) + n)%n
        val rDiff = if (diff == 0) n else diff
        if (visit(rDiff - 1) > 0 && visit(rDiff - 1) != arr(index - 1)) possible = false
        result(arr(index - 1) - 1) = rDiff
        visit(rDiff - 1) = arr(index - 1)
      }
    }
    // Fill remaining with unvisited
    val available = result.zipWithIndex.filter(x => x._1 == 0).map(_._2)
    val unvisited = visit.zipWithIndex.filter(x =>  x._1 == 0).map(_._2)
    if (available.size != unvisited.size) possible = false
    (available zip unvisited).foreach { pair =>
      result(pair._1) = pair._2 + 1
    }
    if (possible == false) println(-1) else println(result.mkString(" "))
  }
}
