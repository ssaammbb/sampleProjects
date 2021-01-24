package edu.colorado.csci3155.project2
import scala.annotation.tailrec

/* A class to maintain a canvas. */
import java.awt.geom.{Ellipse2D, Rectangle2D}
import java.awt.{Graphics2D}

/* A figure is a sealed trait. It can be a Polygon or a "MyCircle"*/
sealed trait Figure {
    def getBoundingBox: (Double, Double, Double, Double)
    def translate(shiftX: Double, shiftY: Double): Figure

    def render(g: Graphics2D, scaleX: Double, scaleY: Double, shiftX: Double, shiftY: Double): Unit
}

/*
 Class Polygon
   A polygon is defined by a list of its vertices
 */


case class Polygon(val cList: List[(Double, Double)]) extends Figure {
    //TODO: Define the bounding box of the polygon
    override def getBoundingBox: (Double, Double, Double, Double ) = {
        val xlist = cList.map(x=> x._1)
        val ylist = cList.map(x=> x._2)
        val xmin = xlist.min; val xmax = xlist.max; val ymin = ylist.min; val ymax = ylist.max
        val ans = (xmin,xmax,ymin,ymax)
        ans

    }




    //TODO: Create a new polygon by shifting each vertex in cList by (x,y)
    //    Do not change the order in which the vertices appear
    override def translate(shiftX: Double, shiftY: Double): Polygon = {
        val xlist = cList.map(x=> x._1)
        val ylist = cList.map(x=> x._2)
        val clist = xlist.map(x => x+shiftX) zip ylist.map(x => x+shiftY)
        val poly = new Polygon(clist)
        poly

    }

    // Function: render -- draw the polygon. Do not edit this function.
    override def render(g: Graphics2D, scaleX: Double, scaleY: Double, shiftX: Double, shiftY: Double) = {
        val xPoints: Array[Int] = new Array[Int](cList.length)
        val yPoints: Array[Int] = new Array[Int](cList.length)
        for (i <- 0 until cList.length){
            xPoints(i) = ((cList(i)._1 + shiftX )* scaleX).toInt
            yPoints(i) = ((cList(i)._2 + shiftY) * scaleY).toInt
        }
        g.drawPolygon(xPoints, yPoints, cList.length)
    }
}

/*
  Class MyCircle
  Define a circle with a given center c and radius r
 */
case class MyCircle(val c: (Double, Double), val r: Double) extends Figure {
    //TODO: Define the bounding box for the circle
    override def getBoundingBox: (Double, Double, Double, Double) = {
        val bb = (c._1-r, c._1+r, c._2-r, c._2+r)
        bb
    }


    //TODO: Create a new circle by shifting the center
    override def translate(shiftX: Double, shiftY: Double): MyCircle = {
        val newC = (c._1+shiftX, c._2+shiftY)
        val circ = new MyCircle(newC, r)
        circ
    }

    // Function: render -- draw the polygon. Do not edit this function.
    override def render(g: Graphics2D, scaleX: Double, scaleY: Double, shiftX: Double, shiftY: Double) = {
        val centerX = ((c._1 + shiftX) * scaleX) .toInt
        val centerY = ((c._2 + shiftY) * scaleY) .toInt
        val radX = (r * scaleX).toInt
        val radY = (r * math.abs(scaleY)).toInt
        //g.draw(new Ellipse2D.Double(centerX, centerY, radX, radY))
        g.drawOval(centerX-radX, centerY-radY, 2*radX, 2*radY)
    }
}

/*
  Class : MyCanvas
  Define a canvas through a list of figure objects. Figure objects can be circles or polygons.
 */
class MyCanvas (val listOfObjects: List[Figure]) {
    // TODO: Write a function to get the boundingbox for the entire canvas.
    // Hint: use existing boundingbox functions defined in each figure.
    def getBoundingBox: (Double, Double, Double, Double) = {
        val bbs = listOfObjects.map(x => x.getBoundingBox)
        val xmin = bbs.map(x => x._1)
        val xmax = bbs.map(x => x._2)
        val ymin = bbs.map(x => x._3)
        val ymax = bbs.map(x => x._4)
        val ans = (xmin.min,xmax.max,ymin.min,ymax.max)
        ans
    }

    //TODO: Write a function to translate each figure in the canvas by shiftX, shiftY
    def translate(shiftX: Double, shiftY: Double): MyCanvas = {
        val trans = listOfObjects.map(x => x.translate(shiftX, shiftY))
        val canvas = new MyCanvas(trans)
        canvas
    }

    //TODO: Write a function that will return a new MyCanvas object that places
    // all the objects in myc2 to the right of the objects in this MyCanvas.
    // refer to the notebook documentation on how to perform this.
    def placeRight(myc2: MyCanvas):MyCanvas = {

        val bb1 = this.getBoundingBox
        val bb2 = myc2.getBoundingBox
        val xshift = (bb1._2 - bb1._1)
        val yshift = (bb1._4 - bb1._3)/2 - (bb2._4 - bb2._3)/2
        val c2hat = myc2.translate(xshift,yshift)
        val ans = this.overlap(c2hat)
        ans
    }

    //TODO: Write a function that will return a new MyCanvas object that places
    // all the figures in myc2 on top of the figures in this MyCanvas.
    // refer to the notebook documentation on how to perform this.
    def placeTop(myc2: MyCanvas): MyCanvas = {
        val bb1 = this.getBoundingBox
        val bb2 = myc2.getBoundingBox
        val xshift = (bb1._2 - bb1._1)/2 - (bb2._2 - bb2._1)/2
        val yshift = (bb1._4 - bb1._3)
        val c2hat = myc2.translate(xshift,yshift)
        val ans = this.overlap(c2hat)
        ans
    }

    //TODO: Write a function that will rotate each figure in the canvas using
    // the angle `ang` defined in radians.
    // Suggestion: first write rotation functions for polygon and circle.
    //             those functions have not been added in the classes but you can do so with the
    //             appropriate signature.
    // rotating a polygon is simply rotating each vertex.
    // rotating a circle is simply rotating the center with radius unchanged.

    @tailrec
    private def polyHelper(cList: List[(Double,Double)], angRad: Double, n: Int): List[(Double, Double)] = {
        if(n == cList.length){
            cList
        }else{
            val xprime = cList(n)._1*Math.cos(angRad) - cList(n)._2*Math.sin(angRad)
            val yprime = cList(n)._1*Math.sin(angRad) + cList(n)._2*Math.cos(angRad)
            val coord = (xprime,yprime)
            val newL = cList.slice(0,n) ++ List(coord) ++ cList.slice(n,cList.length-1)
            val newn = n + 1
            polyHelper(newL, angRad, newn)

        }
    }

    def rotateShape(angRad: Double, shape: Figure): Figure = {
        shape match{
            case MyCircle(c, r) => {
                val xprime = c._1*Math.cos(angRad) - c._2*Math.sin(angRad)
                val yprime = c._1*Math.sin(angRad) + c._2*Math.cos(angRad)
                val coord = (xprime, yprime)
                val newCirc = new MyCircle(coord, r)
                newCirc
            }
            case Polygon(cList) => {

                val p = polyHelper(cList, angRad, 0)
                val poly = new Polygon(p)
                poly


            }
        }
    }

    def rotate(angRad: Double): MyCanvas = { // See helper functions rotateShape and polyHelper above
        val callRotate = listOfObjects.map(x => rotateShape(angRad,x))
        val newC = new MyCanvas(callRotate)
        newC

    }

    // Function to draw the canvas. Do not edit.
    def render(g: Graphics2D, xMax: Double, yMax: Double) = {
        val (lx1, ux1, ly1, uy1) = this.getBoundingBox
        val shiftx = -lx1
        val shifty = -uy1
        val scaleX = xMax/(ux1 - lx1  + 1.0)
        val scaleY = yMax/(uy1 - ly1 + 1.0)
        listOfObjects.foreach(f => f.render(g,scaleX, -scaleY, shiftx, shifty))
    }

    def overlap(c2: MyCanvas): MyCanvas = {
        new MyCanvas(listOfObjects ++ c2.listOfObjects)
    }

    // DO NOT EDIT THE CODE BELOW
    override def toString: String = {
        listOfObjects.foldLeft[String] ("") { case (acc, fig) => acc ++ fig.toString }
    }
    // DO NOT EDIT
    def getListOfObjects: List[Figure] = listOfObjects

    // DO NOT EDIT
    def numPolygons: Int =
        listOfObjects.count {
            case Polygon(_) => true
            case _ => false }

    //DO NOT EDIT
    def numCircles: Int = {
        listOfObjects.count {
            case MyCircle(_,_) => true
            case _ => false }
    }
    //DO NOT EDIT
    def numVerticesTotal: Int = {
        listOfObjects.foldLeft[Int](0) ((acc, f) =>
            f match {
                case Polygon(lst1) => acc + lst1.length
                case _ => acc
            }
        )
    }
}
