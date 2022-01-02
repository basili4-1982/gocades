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
	about.MediaFilter(MEDIA_TYPE_SCARD)
	about.ReaderFilter(ENABLE_ANY_CARRIER_TYPE, DISABLE_EVERY_CARRIER_OPERATION, ".*rutoken.*")
}

func TestVersion(t *testing.T) {
	about, _ := About()
	version, _ := about.GetCSPVersion("", 80)
	version.ToString()
	version.GetMajorVersion()
	version.GetMinorVersion()
	version.GetBuildVersion()
}
