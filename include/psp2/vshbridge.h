/**
 * \usergroup{SceVshBridge}
 * \usage{psp2/vshbridge.h,SceVshBridge_stub}
 */

#ifndef _PSP2_VSHBRIDGE_H_
#define _PSP2_VSHBRIDGE_H_

#include <psp2/types.h>
#include <psp2/kernel/modulemgr.h>

#ifdef __cplusplus
extern "C" {
#endif

int _vshSblGetSystemSwVersion(SceKernelFwInfo * data);

int _vshSblAimgrGetConsoleId(char CID[32]);

/**
 * @param[in] id - mount id
 * @param[in] path - mount path
 * @param[in] permission - 1/RO 2/RW
 * @param[in] buf - work buffer
 *
 * @return 0 >= on success, < 0 on error.
 */
int _vshIoMount(int id, const char *path, int permission, void* buf);

/**
 * @param[in] id - mount id
 * @param[in] force - Set to 1 to force umount
 * @param[in] unk2 - Unknown, set 0
 * @param[in] unk3 - Unknown, set 0
 *
 * @return 0 >= on success, < 0 on error.
 */
int vshIoUmount(int id, int force, int unk2, int unk3); 

int vshIdStorageIsDirty(void);
int vshIdStorageIsFormatted(void);
int vshIdStorageIsReadOnly(void);

/**
 * @param[in] leafnum - 0x0 ~ 0x80 / leafnum > 0x80 = error
 * @param[out] buf    - Leaf data, size is 512 byte
 *
 * @return 0 on success, < 0 on error.
 */
int vshIdStorageReadLeaf(int leafnum, void *buf);

/**
 * @param[in] leafnum - 0x0 ~ 0x80 / leafnum > 0x80 = error
 * @param[in] buf     - Leaf data, size is 512 byte
 *
 * @return 0 on success, < 0 on error.
 */
int vshIdStorageWriteLeaf(int leafnum, const void *buf);

int vshSblAimgrIsCEX(void);
int vshSblAimgrIsDEX(void);
int vshSblAimgrIsVITA(void);
int vshSblAimgrIsGenuineVITA(void);
int vshSblAimgrIsDolce(void);
int vshSblAimgrIsGenuineDolce(void);
int vshSblAimgrIsTest(void);
int vshSblAimgrIsTool(void);
int vshSblSsIsDevelopmentMode(void);

int vshSysconHasWWAN(void);

int vshSysconIsDownLoaderMode(void);
int vshSysconIsIduMode(void);
int vshSysconIsMCEmuCapable(void);
int vshSysconIsShowMode(void);

int vshSysconIduModeSet(void);
int vshSysconIduModeClear(void);

int vshSysconShowModeSet(void);
int vshSysconShowModeClear(void);

int vshMemoryCardGetCardInsertState(void);
int vshRemovableMemoryGetCardInsertState(void);

#ifdef __cplusplus
}
#endif

#endif /* _PSP2_VSHBRIDGE_H_ */
