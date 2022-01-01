package gocades

import (
	"testing"
)

func TestAboutGetVersion(t *testing.T) {
	about := About()
	about.GetVersion()
}

func TestAboutGetMajorVersion(t *testing.T) {
	about := About()
	about.GetMajorVersion()
}

func TestAboutGetMinorVersion(t *testing.T) {
	about := About()
	about.GetMinorVersion()
}

func TestAboutGetBuildVersion(t *testing.T) {
	about := About()
	about.GetBuildVersion()
}
