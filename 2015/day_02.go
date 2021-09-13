package main

import (
	"fmt"
	"sort"
	"strings"
)

type Dimension struct {
	l, w, h int
}

func (d *Dimension) getSmallestArea() int {
	sizes := []int{d.l, d.w, d.h}
	sort.Ints(sizes)
	total := sizes[0] * sizes[1]
	return total
}

func (d *Dimension) getSurfaceArea() int {
	smallestSide := d.getSmallestArea()
	return (2 * (d.l * d.w)) + (2 * (d.w * d.h)) + (2 * (d.h * d.l)) + smallestSide
}

func main() {
	input := `29x13x26
	11x11x14`
	fmt.Println(strings.Split(input, "\t"))

}
