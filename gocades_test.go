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

func TestAttribute(t *testing.T) {
	attribute, _ := Attribute()
	attribute.PutValue("ABCD")
	attribute.GetValue()
	attribute.PutName(2)
	attribute.GetName()
	attribute.PutValueEncoding(1)
	attribute.GetValueEncoding()
	attribute.PutOID("1.2.3.3.5")
	attribute.GetOID()
}

func TestOID(t *testing.T) {
	attribute, _ := Attribute()
	oid, _ := attribute.GetOID()
	oid.SetFriendlyName("ГОСТ Р 34.10-2001")
	oid.GetFriendlyName()
	oid.GetValue()
	oid.SetValue("1.2.643.7.1.1.2.2")
	oid.GetFriendlyName()
	oid.SetName(1)
	oid.GetName()
	oid.GetValue()
}
