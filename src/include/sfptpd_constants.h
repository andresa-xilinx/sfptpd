/* SPDX-License-Identifier: BSD-3-Clause */
/* (c) Copyright 2012-2021 Xilinx, Inc. */

#ifndef _SFPTPD_CONSTANTS_H
#define _SFPTPD_CONSTANTS_H

#include "sfptpd_version.h"


/** Manufacturer string */
#define SFPTPD_MANUFACTURER "Xilinx, Inc."

/** Model string */
#define SFPTPD_MODEL "sfptpd"

/** Default user description */
#define SFPTPD_USER_DESCRIPTION "Solarflare Enhanced PTP Daemon"

/** Solarflare OUI */
#define SFPTPD_OUI0 (0x00U)
#define SFPTPD_OUI1 (0x0FU)
#define SFPTPD_OUI2 (0x53U)

/** Clock delta threshold above which the servo will step the clock */
#define SFPTPD_SERVO_CLOCK_STEP_THRESHOLD  (1000000000LL)

/** Clock servo filter stiffness */
#define SFPTPD_SERVO_FILTER_STIFFNESS_MIN  (1)
#define SFPTPD_SERVO_FILTER_STIFFNESS_MAX  (16)

/** Xilinx NIC PCI Vendor IDs */
#define SFPTPD_SOLARFLARE_PCI_VENDOR_ID  (0x1924)
#define SFPTPD_XILINX_PCI_VENDOR_ID (0x10EE)

/** Maximum length for a version string - daemon, driver or firmware */
#define SFPTPD_VERSION_STRING_MAX (48)

/** VPD NIC product name maximum length */
#define SFPTPD_NIC_PRODUCT_NAME_MAX (128)

/** VPD NIC model number maximum length */
#define SFPTPD_NIC_MODEL_MAX (32)

/** VPD NIC serial number maximum length */
#define SFPTPD_NIC_SERIAL_NUM_MAX (64)

/** sfptpd state path. Default complies with FHS 3.0.
 *  http://refspecs.linuxfoundation.org/FHS_3.0/fhs/ch05s08.html */
#define SFPTPD_STATE_PATH  "/var/lib/sfptpd"

/** sfptpd control socket path */
#define SFPTPD_CONTROL_SOCKET_PATH  "/var/run/sfptpd-control-v1.sock"

/** Statistics logging interval in seconds */
#define SFPTPD_STATISTICS_LOGGING_INTERVAL (1)

/** State save interval in seconds */
#define SFPTPD_STATE_SAVE_INTERVAL (60)

/** Long-term statistics collection */
#define SFPTPD_STATS_COLLECTION_INTERVAL (60)

/** Minimum and maximum intervals before and after leap second during which
 * timestamp processing and clock updates are suspended */
#define SFPTPD_LEAP_SECOND_GUARD_INTERVAL_MIN (2.0)
#define SFPTPD_LEAP_SECOND_GUARD_INTERVAL_MAX (10.0)

/** If the NIC time is before this then we assume that it has never been set.
 * Current value is one year after the epoch i.e. 1971 */
#define SFPTPD_NIC_TIME_VALID_THRESHOLD (31536000)

/** Topology file field width */
#define SFPTPD_TOPOLOGY_FIELD_WIDTH (35)

/** Maximum VLAN tags */
#define SFPTPD_MAX_VLAN_TAGS (3)

/** Number and size of messages in the global message pool */
#define SFPTPD_NUM_GLOBAL_MSGS (256)
#define SFPTPD_SIZE_GLOBAL_MSGS (256)

/** Additional errnos */
/** Failure to retrieve a timestamp for a packet */
#define ENOTIMESTAMP    (1000)

/** Notional accuracies associated with each type of module in ns */
#define SFPTPD_ACCURACY_FREERUN		(0.0)
#define SFPTPD_ACCURACY_NTP		(10.0e6)	/* 10ms */
#define SFPTPD_ACCURACY_PPS		(50.0)		/* 50ns */
#define SFPTPD_ACCURACY_PTP_HW		(50.0)		/* 50ns */
#define SFPTPD_ACCURACY_PTP_SW		(50.0e3)	/* 50us */
#define SFPTPD_ACCURACY_GPS		(500.0e6)	/* 500ms */

/** Extra servos for interfaces that could be added at runtime */
#define SFPTPD_EXTRA_SERVOS_FOR_HOTPLUGGING (16)

/** Macros for turning preprocessor values into strings */
#ifndef STRINGIFY
#define STRINGIFY(x) _STRINGIFY(x)
#define _STRINGIFY(x) #x
#endif

/** PTP Profiles.
    Order important: values index into profile definitions. */
typedef enum sfptpd_ptp_profile {
	SFPTPD_PTP_PROFILE_UNDEF = -1,
	SFPTPD_PTP_PROFILE_DEFAULT_E2E = 0,
	SFPTPD_PTP_PROFILE_DEFAULT_P2P,
	SFPTPD_PTP_PROFILE_ENTERPRISE,
} sfptpd_ptp_profile_t;

/** Number of seconds of sustained sync failures before raising
    servo alarm. */
#define SFPTPD_SUSTAINED_SYNC_FAILURE_PERIOD (30)

#endif /* _SFPTPD_CONSTANTS_H */
