package gocades

import (
	"testing"
)

func TestAboutGetVersion(t *testing.T) {
	about := About()
	about.GetVersion()
}
