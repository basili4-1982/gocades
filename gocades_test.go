package gocades

import (
	"testing"
)

func TestAbout(t *testing.T) {
	about, _ := About()
	about.GetVersion()
	about.GetMajorVersion()
	about.GetMinorVersion()
	about.GetBuildVersion()
	about.GetCSPVersion("", 80)
	about.GetCSPName(80)
	about.MediaFilter(2)
	about.ReaderFilter(1, 0, ".*rutoken.*")
}

func TestVersion(t *testing.T) {
	about, _ := About()
	version, _ := about.GetCSPVersion("", 80)
	version.ToString()
	version.GetMajorVersion()
	version.GetMinorVersion()
	version.GetBuildVersion()
}
