# -*- mode: python -*-

block_cipher = None


a = Analysis(['D:\\wei\\weiProgramme\\projects\\graduation\\qtTree\\pyqtTree.py'],
             pathex=['D:\\wei\\weiProgramme\\projects\\graduation\\qtTree'],
             binaries=[],
             datas=[],
             hiddenimports=[],
             hookspath=[],
             runtime_hooks=['rthook_pyqt4.py'],
             excludes=[],
             win_no_prefer_redirects=False,
             win_private_assemblies=False,
             cipher=block_cipher)
pyz = PYZ(a.pure, a.zipped_data,
             cipher=block_cipher)
exe = EXE(pyz,
          a.scripts,
          a.binaries,
          a.zipfiles,
          a.datas,
          name='pyqtTree',
          debug=False,
          strip=False,
          upx=True,
          console=False )
