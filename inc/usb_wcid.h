#ifndef _USB_WCID_H
#define _USB_WCID_H

/** Device control request used for retrieving the OS Feature descriptors of the device. */
#define REQ_GetOSFeatureDescriptor       0x20

/** Descriptor index for a Microsoft Proprietary Extended Device Compatibility descriptor. */
#define EXTENDED_COMPAT_ID_DESCRIPTOR    0x0004

/** Descriptor index for a Microsoft Proprietary Extended Device Properties OS Feature Descriptor. */
#define EXTENDED_PROPERTIES_DESCRIPTOR   0x0005

#define NB_PROPERTIES          1

typedef struct {
	uint8_t Size;
	uint8_t Type;
	uint8_t Signature[7*2];
	uint8_t VendorCode;
	uint8_t Reserved;
} USB_OSDescriptor_t;

typedef struct {
	uint8_t FirstInterfaceNumber;
	uint8_t Reserved;
	uint8_t CompatibleID[8];
	uint8_t SubCompatibleID[8];
	uint8_t Reserved2[6];
} USB_OSCompatibleSection_t;

typedef struct {
	uint32_t TotalLength;
	uint16_t Version;
	uint16_t Index;
	uint8_t TotalSections;
	uint8_t Reserved[7];
	USB_OSCompatibleSection_t CompatID;
} USB_OSCompatibleIDDescriptor_t;


typedef struct __attribute__((packed)) {
	uint32_t TotalLength;
	uint16_t Version;
	uint16_t Index;
	uint16_t TotalSections;

	uint32_t Length;
	uint32_t Type;

	uint16_t NameLength;
	uint16_t NameValue[20];

	uint32_t DataLength;
	uint16_t DataValue[39];

} USB_OSPropertiesDescriptor_t;


#endif
